/*
 * Demo1_6 indicates the action of compiler and assembler
 * calling two functions that share the same static member
 * so the assembler faces the duplicated version
 *
 * seems the two .out files are the same(orz)
 * try nm -C *.out |grep [funcname]|grep w again
 */
#include <iostream>
void call();
void call1();
using namespace std;
int main() {
    call();
    call1();
    cout<<"the second test"<<endl;
    cout<<"this test is for changing push author"<<endl;
    cout<<"the author now is alex2097"<<endl;
    return 0;
}