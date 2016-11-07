#include <iostream>
#include <string>
#include "hetero_stack.h"
/*
 * Demo1_5 firstly implements a simple stack of which the elements can be of different types
 * then it implements a hetero_stack, which means a stack with elements with different types
 */
int main() {
    typedef hetero_node<int,void> node_0;
    typedef hetero_node<char,node_0> node_1;
    typedef hetero_node<std::string,node_1> node_2;

    node_2 *p2=push(std::string("Awesome!"),push('a',push(1,(void *)0)));

    std::cout<<p2->value<<",  "
             <<p2->next->value<<",  "
             <<p2->next->next->value<<std::endl;
    pop(pop(pop(p2)));

    return 0;
}