//
// Created by alex on 16-10-26.
//
#include <istream>
#include <stdexcept>
#ifndef DEMO1_5_STACK_H
#define DEMO1_5_STACK_H

#endif //DEMO1_5_STACK_H
template <typename T> class my_stack;

template <typename T>
class list_node{
    T value;
    list_node *next;
    list_node(T const &v,list_node*n):value(v),next(n){}
    friend class my_stack<T>;
};

template <typename T=int>
class my_stack{
    typedef list_node<T> node_type;
    node_type *head;
    my_stack operator=(my_stack const &){}
    my_stack(my_stack const &s){}
public:
    my_stack():head(0){}
    ~my_stack(){
        while(!empty()) pop();
    }

    bool empty() const{return head==0;}
    T const &top() const throw(std::runtime_error){
        if(empty()) throw std::runtime_error::("stack is empty.");
        return  head->value;
    }

    void push(T const &v){
        head=new node_type(v,head);
    }

    void pop();
};

template <typename T>
void my_stack<T>::pop() {
    if(head){
        node_type *tmp=head;
        head=head->next;
        delete(tmp);
    }
}
