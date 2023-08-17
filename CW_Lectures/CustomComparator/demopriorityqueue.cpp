#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool cmp(int a, int b) {
    return a>b;
}

class Customcomparator {
    public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {

    vector<int> v = {4,3,5,1,6,17};
    
    // priority_queue<int, vector<int> , function<bool(int, int)> > pq(cmp);
    priority_queue<int, vector<int> , Customcomparator > pq;
    pq.push(5);
    pq.push(4);
    pq.push(3);


    cout<<pq.top()<<" ";

    return 0;
}