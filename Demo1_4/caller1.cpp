//
// Created by alex on 16-10-13.
//
#include <iostream>
using namespace std;
template <typename T>
void func(T const& v){
    cout<<"function1"<<v<<endl;
}

void caller1(){
    func(1);
    func(0.1);
}