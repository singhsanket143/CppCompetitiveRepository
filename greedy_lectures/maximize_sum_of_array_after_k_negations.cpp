#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {

    return 0;
}
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) { //O(klogn + n)
        priority_queue<int, vector<int>, greater<int> > pq(nums.begin(), nums.end()); // O(n)
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) sum += nums[i]; // O(n)
        while(k--) { //O(klogn)
            int el = pq.top(); // min el
            if(el == 0) {
                // break
                break;
            }
            pq.pop(); // remove the smallest
            sum -= el;
            pq.push(-1*el); // add the negated number
            sum += (-el);
        }
        return sum;
    }
};