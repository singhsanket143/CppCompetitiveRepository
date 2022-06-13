// https://leetcode.com/problems/unique-binary-search-trees/i
class Solution {
public:
    int numTrees(int n) {
        std::vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= i; j++) { // this loop gives the chance to all nodes from 1 - i to become root
                dp[i] += (dp[j-1] * dp[i-j]);
            }
        }
        return dp[n];
    }
    
};