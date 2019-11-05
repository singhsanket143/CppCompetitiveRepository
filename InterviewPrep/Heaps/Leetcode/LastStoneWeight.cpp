#include "iostream"
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> qu;
        for(int i=0;i<stones.size();i++) {
            qu.push(stones[i]);
        }
        while(qu.size()>1) {
            int x = qu.top();
            qu.pop();
            int y = qu.top();
            qu.pop();
            if (x == y) continue;
            else if (x != y) {
                y = abs(y - x);
                qu.push(y);
            }
        } 
        if(qu.size() == 0) return 0;
        return qu.top();
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}