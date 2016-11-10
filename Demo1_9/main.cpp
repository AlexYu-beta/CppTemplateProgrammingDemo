#include <iostream>
/*
 * Demo1_9 implements foreach function by using function pointer as a template parameter
 */
using namespace std;

template <typename T,void (*f)(T &v)>
void foreach(T array[], unsigned size){
    for(unsigned i=0;i<size;i++) f(array[i]);
};

template <typename T>
void inc(T &v){
    ++v;
}

template <typename T>
void dec(T &v){
    --v;
}

template <typename T>
void print(T &v){
    cout<<' '<<v;
}


int main() {
    int array1[]={1,2,3,4,5,6,7,8};
    char array2[]={'a','b','c','d','e'};
    foreach<int,print<int>>(array1,8);
    foreach<int,inc<int>>(array1,8);
    foreach<int,print<int>>(array1,8);
    cout<<endl;
    foreach<char,print<char>>(array2,5);
    foreach<char,inc<char>>(array2,5);
    foreach<char,print<char>>(array2,5);
    return 0;
}