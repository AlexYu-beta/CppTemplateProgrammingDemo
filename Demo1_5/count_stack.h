//
// Created by alex on 16-10-26.
//
#include "stack.h"
#ifndef DEMO1_5_COUNT_STACK_H
#define DEMO1_5_COUNT_STACK_H

#endif //DEMO1_5_COUNT_STACK_H
template <typename T=int>
class count_stack:public my_stack<T>{
    typedef my_stack<T> base_type;
    unsigned size;
public:
    count_stack():base_type(),size(0){}
    void push(T const &v){
        base_type::push(v);
        size++;
    }

    void pop(){
        if(size>0){
            base_type::pop();
            size--;
        }
    }

    unsigned getSize() const{return size;}
};