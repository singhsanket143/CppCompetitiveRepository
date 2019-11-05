#include "iostream"
using namespace std;
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > qu;
    int sz;
    KthLargest(int k, vector<int>& nums) {
        this->sz = k;
        for(int i = 0; i < k and i < nums.size(); i++) {
            qu.push(nums[i]);
        }
        for(int i = k; i < nums.size(); i++) {
            if(nums[i] >= qu.top()) {
                qu.pop();
                qu.push(nums[i]);
            }
        }
    }
    
    int add(int val) {  
        if(qu.size() != this->sz) {
            qu.push(val);
            return qu.top();
        }
        if(!qu.empty() and val >= qu.top()) {
            qu.pop();
            qu.push(val);
        } else if (qu.empty()) {
            qu.push(val);
        }
        int x = qu.top();
        return x;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}