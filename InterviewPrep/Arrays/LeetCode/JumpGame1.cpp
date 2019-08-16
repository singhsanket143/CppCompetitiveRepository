#include <iostream>
using namespace std;
bool canJump(vector<int>& nums) {
    if (nums.size() == 1) return true;
    int n = nums.size();
    int *dp = new int[n]();
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        int min_level = INT_MAX;
        int steps = nums[i];
        int j = i + 1;
        while (steps--) {
            if (j >= n) break;
            min_level = min(min_level, dp[j]);
            j++;
        }
        dp[i] = min_level == INT_MAX ? INT_MAX : min_level + 1;
    }
    return dp[0] != INT_MAX;
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
