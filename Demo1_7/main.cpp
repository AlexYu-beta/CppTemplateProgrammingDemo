#include <iostream>
#include <stdexcept>
/*
 * Demo1_7 implements array with variant length by introducing an integer template parameter to hold the length
 * of the array
 */
using namespace std;
template <typename T,unsigned size>
class array{
    T element[size];
public:
    T&operator [](unsigned i) throw(out_of_range){
        if(i>=size){
            throw(out_of_range("array out of range"));
        }else return element[i];
    }

};

int main() {
    array<char,20>array0;
    array<int,10>array1;
    array0[10]='b';
    try{
        array1[10]='c';
    }catch(out_of_range& e){
        cerr<<"Access  "<<" out of range!!"<<endl;
    }
    return 0;
}