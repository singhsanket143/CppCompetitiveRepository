#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1) {
            int p1 = pq.top(); // max
            pq.pop();
            int p2 = pq.top(); // 2nd max
            pq.pop();
            
            int sub = abs(p1 - p2);
            if(sub != 0) pq.push(sub);
        }
        if(pq.size() == 0) return 0;
        return pq.top();
    }
};