//
// Created by alex on 16-11-12.
//

#ifndef DEMO1_10_MY_VECTOR_H
#define DEMO1_10_MY_VECTOR_H
#include <iostream>
#include <stdexcept>
#include <cstdlib>
using namespace std;
template <typename T>
class my_vector{
    T *array;
    unsigned size;
    unsigned block_size;
public:
    my_vector(unsigned bsz): array((T*)malloc(sizeof(T)*bsz)),size(0),block_size(bsz){}
    ~my_vector(){if(array) free(array);}

    void push_back(T const &elem) throw(runtime_error){
        if(size==block_size){
            //run out of block_size, more space needed for the vector
            block_size*=2;
            T* new_array=(T*)realloc(array,block_size* sizeof(T));
            if(new_array!=NULL) array=new_array;
            else{
                //failed to apply for more space because out of memory
                free(array);
                array=NULL;
                throw runtime_error("Out of memory");
            }
        }
        array[size++]=elem;
    }

    T& operator[] (unsigned i){return array[i];}

    const T&operator[] (unsigned i)const{return array[i];}
    //tell how much space been occupied
    unsigned get_mem_size() const{return block_size*sizeof(T);}
};


template<>
class my_vector<bool>{
    int *array;
    unsigned size;
    unsigned block_size;
    const static unsigned seg_size;
    //the segment size of a boolean, 8 in C++
public:
    my_vector(unsigned bsz=1):array((int *)malloc(sizeof(int)*bsz)),size(0),block_size(bsz){}
    ~my_vector(){if(array) free(array);}

    void push_back(bool elem) throw(runtime_error){
        if(size==block_size*seg_size){
            block_size*=2;
            int *new_array=(int *)realloc(array,block_size*sizeof(int));
            if(new_array!= NULL)array=new_array;
            else{
                free(array);
                array=NULL;
                throw runtime_error("Out of memory");
            }
        }
        set(size++,elem);
    }

    void set(unsigned i, bool elem){
        if(elem){
            array[i/seg_size]|=(0x1<<(i%seg_size));
        }else{
            array[i/seg_size]&=~(0x1<<(i%seg_size));
        }
    }

    bool operator [] (unsigned i)const{
        return(array[i/seg_size]&(0x1<<(i%seg_size)))!=0;
    }

    unsigned get_mem_size()const{
        return block_size*sizeof(int);
    }
};

const unsigned my_vector<bool>::seg_size=sizeof(int)*8;
#endif //DEMO1_10_MY_VECTOR_H
