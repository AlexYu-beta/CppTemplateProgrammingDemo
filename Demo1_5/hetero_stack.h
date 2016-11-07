//
// Created by alex on 16-10-26.
//
#include<iostream>
using namespace std;
#ifndef DEMO1_5_HETERO_STACK_H
#define DEMO1_5_HETERO_STACK_H

#endif //DEMO1_5_HETERO_STACK_H
template <typename T,typename  N>
struct hetero_node{
    T value;
    N* next;
    hetero_node(T const &v, N *n):value(v),next(n){}
};

template <typename T,typename N>
hetero_node<T,N> *push(T const &v,N *n){
    return new hetero_node<T,N>(v,n);
};

template <typename T,typename N>
N *pop(hetero_node<T,N> *head){
    N *next=head->next;
    delete(head);
    return next;
};