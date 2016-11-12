#include <iostream>
#include "my_vector.h"
/*
 * Demo1_10 implements a self-defined template class to mock vector
 * , with which I can experiment on the tps(template partial specification)
 *
 * As we all know, a boolean value does not need to take up too much memory space,
 * so if we also apply bytes for a boolean vector, it costs a lot,
 * therefore it's essential to create a partial specification for the boolean vector
 */
using namespace std;
int main() {
    my_vector<char> va(2);
    my_vector<bool> vb(2);
    for(unsigned i=0;i<20;i++){
        va.push_back('a'+i);
        vb.push_back(i%4==0);
    }
    cout<<"Memory size of my_vector<char>: "<<va.get_mem_size()<<endl;
    cout<<"Memory size of my_vector<bool>: "<<vb.get_mem_size()<<endl;
    for(unsigned i=0;i<20;i++){
        cout<<"  "<<va[i];
    }
    cout<<endl;
    for(unsigned i=0;i<20;i++){
        cout<<"  "<<vb[i];
    }
    cout<<endl;
    return 0;
}