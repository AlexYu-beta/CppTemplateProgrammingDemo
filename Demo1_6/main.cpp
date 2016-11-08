/*
 * Demo1_6 indicates the action of compiler and assembler
 * calling two functions that share the same static member
 * so the assembler faces the duplicated version
 *
 * seems the two .out files are the same(orz)
 */
#include <iostream>
void call();
void call1();
using namespace std;
int main() {
    call();
    call1();
    return 0;
}