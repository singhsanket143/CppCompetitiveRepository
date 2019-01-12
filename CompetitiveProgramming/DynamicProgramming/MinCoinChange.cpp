#include <bits/stdc++.h>
using namespace std;

int minCoinChangeBottomUp(int *coins, int value, int n) {
    int *dp = new int[value+1];
    dp[0] = 0;
    for(int i=1;i<=value;i++) {
        int currentVal = INT_MAX;
        for(int j=0;j<n;j++) {
            if(i-coins[j]<0) {
                continue;
            }
            currentVal = min(currentVal, 1+(dp[i-coins[j]]));
        }
        dp[i] = currentVal;
    }
    return dp[value];
}

int minCoinChangeTopDown(int *coins, int value, int n, int *dp) {
    if(value<0) {
        return INT_MAX;
    }
    if(value==0) {
        dp[0] = 0;
        return 0;
    }
    if(dp[value]!=0) {
        return dp[value];
    }
    int currentVal = INT_MAX;
    for(int i=0;i<n;i++) {
        currentVal = min(currentVal, minCoinChangeTopDown(coins, value-coins[i], n, dp));
    }

    dp[value] = (currentVal==INT_MAX)?-1:1+currentVal;
    return dp[value];
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,s;
    cin>>n>>s;
    int *coins = new int[n];
    for(int i=0;i<n;i++) {
        cin>>coins[i];
    }
    int *dp = new int[1005];
    cout<<minCoinChangeTopDown(coins, s, n, dp);
    return 0;
}
