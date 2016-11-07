/**
 * Demo1_4 indicates that repeated declaration of function template should be eliminated by compiler,
 * thus, in this demo, caller2 can only call the function template described in caller1.cpp
 * try compiling through g++
 * 1. g++ caller1.cpp caller2.cpp -o a.out
 * 2. g++ caller2.cpp caller1.cpp -o a.out.2
 * see where is the difference
 */
#include <iostream>
using namespace std;
void caller1();
void caller2();
int main() {
    caller1();
    caller2();
    return 0;
}