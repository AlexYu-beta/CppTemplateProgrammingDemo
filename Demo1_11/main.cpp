#include <iostream>
#include <queue>
/*
 * Demo1_11 is a simple implementation of priority queue to put the "smallest element" on the top
 * of the "list" in an alphabetical order
 */
#include <vector>
struct SimplePair{
    int first;
    int second;
};

struct _compare_SimplePare{
    bool operator()(SimplePair const& left,SimplePair const& right){
        return left.first==right.first?
               left.second>right.second:left.first>right.first;
    }
};
int main() {
    SimplePair array[]={{3,0},{2,1},{1,2},{0,3},{0,4}};
    using std::priority_queue;
    using std::vector;
    priority_queue<SimplePair,vector<SimplePair>,_compare_SimplePare>pqueue(array,array+5);
    while(!pqueue.empty()){
        std::cout<<pqueue.top().first<<" , "<<pqueue.top().second<<std::endl;
        pqueue.pop();
    }
    return 0;
}