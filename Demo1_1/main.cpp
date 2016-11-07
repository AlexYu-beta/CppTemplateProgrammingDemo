/**
 * Demo1_1 is a simple demonstration of template function to find the maximum of the arrays, which may own different
 * types
 */
#include <iostream>
using namespace std;
template<typename T>
T const& max_element(T const *l, unsigned size){
    T const *max_value(l);
    for(unsigned i=1;i<size;i++){
        if(l[i]> *max_value)max_value=&(l[i]);
    }
    return *max_value;
}

int main() {
    int l[]={2,1,0,0,8,2,5,1};
    char cl[]="August";
    cout<<max_element<int>(l,8)<<endl;
    cout<<max_element<char>(cl,6)<<endl;
    return 0;
}