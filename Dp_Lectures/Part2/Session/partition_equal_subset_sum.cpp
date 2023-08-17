#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > dp;
    bool f(vector<int> &arr, int i, int k) {
        if(k == 0) return true;
        if(i == arr.size()) return false;
        if(dp[i][k] != -1) return dp[i][k];
        if(arr[i] <= k) {
            // we can include or exclude
            return dp[i][k] = f(arr, i+1, k-arr[i]) or f(arr, i+1, k);
        } else {
            // always exclude
            return dp[i][k] = f(arr, i+1, k);
        }
    }
    
    bool canPartition(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++) s+=nums[i];
        if(s%2!=0) return false;
        dp.clear();
        dp.resize(205, vector<int> (20005, false));
        int k = s/2;
        for(int i = 0; i < n; i++) dp[i][0] = true; // base case
        for(int i = n-1; i >= 0; i--) {
            for(int j = 1; j <= k; j++) {
                if(nums[i] <= j)
                    dp[i][j] = dp[i+1][j-nums[i]] or dp[i+1][j];
                else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][k];
    }
};