//
// Created by alex on 16-10-13.
//
#include <iostream>
using namespace std;
template <typename T>
void func(T const& v){
    cout<<"function2"<<v<<endl;
}

void caller2(){
    func(2);
    func(0.2f);
}
