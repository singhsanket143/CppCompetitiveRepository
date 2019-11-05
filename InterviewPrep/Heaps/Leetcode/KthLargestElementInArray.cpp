#include "iostream"
#include "unordered_map"
#include "priority_queue"
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > qu;
        for(int i = 0; i < k; i++) {
            qu.push(nums[i]);
        }
        for(int i = k; i < nums.size(); i++) {
            if(nums[i] >= qu.top()) {
                qu.pop();
                qu.push(nums[i]);
            }
        }
        return qu.top();
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}