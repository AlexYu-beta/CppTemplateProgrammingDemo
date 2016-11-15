#include <iostream>
#include <iomanip>
#include <set>
/*
 * Demo1_12 implements a normal insertion into a integer set and a smarter one.
 * The function "measure" measures the duration of the two insertions and we can point out the differences.
 */

typedef std::set<int> int_set;
typedef void func_type(int*, int*);

float measure(func_type func,int *start, int *end){
    int start_clock=clock();
    func(start,end);
    int end_clock=clock();
    return float(end_clock-start_clock)/CLOCKS_PER_SEC;
}

void normal_insertion(int *start,int *end){
    int_set s;
    s.insert(start,end);
}

void smart_insertion(int *start, int *end){
    int_set s;
    int_set::iterator prev=s.begin();
    for(;start!=end;++start){
        prev=s.insert(prev,*start);
    }
}
int main() {
    const int num=1e6;
    int array1[num];
    int array2[num];
    for(int i=0;i<num;++i){
        array1[i]=i;
        //array1: 0,1,2,3,...
        array2[i]=(i&1)?(i-num):(num-i);
        //array2: 10,-9,8,-7,...

    }
    using namespace std;
    cout<<std::setprecision(2)<<"normal insertion for array1:  "
        <<measure(normal_insertion,array1,array1+num)<<"  sec"<<endl;
    cout<<"smart insertion for array1:  "
        <<measure(smart_insertion,array1,array1+num)<<"  sec"<<endl;
    cout<<"normal insertion for array2:  "
        <<measure(normal_insertion,array2,array2+num)<<"  sec"<<endl;
    cout<<"smart insertion for array2:  "
        <<measure(smart_insertion,array2,array2+num)<<"  sec"<<endl;
    return 0;
}