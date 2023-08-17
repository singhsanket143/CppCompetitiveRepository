#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dp;
    int f(int i) {
        if(i == 0 or i == 1) return 1;
        if(i == 2) return 2;
        if(dp[i] != -1) return dp[i];
        int sum = 0;
        for(int k = 1; k <= i; k++) {
            // k -> potential root
            sum += f(k-1)*f(i-k);
        }
        return dp[i] = sum;
    }
    
    int numTrees(int n) {
        dp.clear();
        dp.resize(30, 0);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++) { // order
            // f(i)
            for(int k = 1; k <= i; k++) {
            // k -> potential root
                dp[i] += dp[k-1]*dp[i-k];
            }
        }
        return dp[n];
    }
};