//
// Created by alex on 16-11-17.
//
#include "object_pool.h"
#include <new>

namespace mylib{
    //being easy to shift the bytes and reinterpret
    template<typename T0, typename T1>
    inline T0 *byte_shift(T1 *ptr,size_t b){
        return reinterpret_cast<T0*>(reinterpret_cast<char*>(ptr)+b);
    };

    void* object_pool::allocate() throw(std::bad_alloc){
        if(!free_node_head){
            //if there is no free node, we should apply for a new chunk and update the chunk list and free_node list
            chunk_data *new_chunk= reinterpret_cast<chunk_data*>(operator new(chunk_size));
            new_chunk->next=chunk_data_head;
            chunk_data_head=new_chunk;
            //cutting chunks into free blocks and inserting them one by one into the free list
            free_node_head=byte_shift<free_node>(new_chunk,chunk_data_size);
            free_node_head->bias=0;
            free_node_head->next=0;
            for(size_t node_index=1;node_index<num_nodes_per_chunk;node_index++){
                free_node *f=byte_shift<free_node>(free_node_head,free_node_size);
                f->bias=free_node_head->bias+1;
                f->next=free_node_head;
                free_node_head=f;
            }
        }

        free_node *return_node=free_node_head;
        free_node_head=free_node_head->next;

        return static_cast<void*>(&(return_node->next));
    }

    void object_pool::deallocate(void *ptr) {
        free_node *f=byte_shift<free_node>(ptr,-1*free_node_offset);
        f->next=free_node_head;
        free_node_head=f;
    }

    size_t object_pool::recycle() {
        //budget for an offset table from free node to chunk
        size_t *shift_table=new size_t[num_nodes_per_chunk];
        shift_table[0]=-1*chunk_data_size;
        for(size_t i=1;i<num_nodes_per_chunk;i++){
            shift_table[i]=shift_table[i-1]-free_node_size;
        }
        //reset free node counter of chunks
        for(chunk_data *p=chunk_data_head;p;p=p->next){
            p->free_node_count=0;
        }
        //access all of the free node and update the counter of the chunks
        for(free_node *f=free_node_head;f;f=f->next){
            chunk_data *chunk=byte_shift<chunk_data>(f,shift_table[f->bias]);
            ++chunk->free_node_count;
        }
        //delete all the nodes where the chunks are free
        for(free_node **pp=&free_node_head;*pp;){
            chunk_data *chunk=byte_shift<chunk_data>(*pp,shift_table[(*pp)->bias]);
            if(chunk->free_node_count==num_nodes_per_chunk){
                *pp=(*pp)->next;
            }else{
                pp=&((*pp)->next);
            }
        }
        //delete all the free chunks from the list
        size_t num_recycled=0;
        for(chunk_data **pp=&chunk_data_head;*pp;){
            if((*pp)->free_node_count==num_nodes_per_chunk){
                chunk_data *p=*pp;
                *pp=(*pp)->next;
                operator delete(p);
                ++num_recycled;
            }else{
                pp=&((*pp)->next);
            }
        }

        delete[]shift_table;
        return num_recycled*chunk_size;
    }
}
