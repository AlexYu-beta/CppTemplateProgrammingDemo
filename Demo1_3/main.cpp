/**
 * Demo1_3 indicates the wrong usage of putting template declarations into head files(separating them from
 * calls in main.cpp)
 */
#include <iostream>
//#include "func.h"
#include "funcnew.h"
using namespace std;

int main() {
    func(0);
    return 0;
}