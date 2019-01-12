#include <iostream>
using namespace std;

int CoinChangeBottomUp(int *coins, int value, int n) {
    int *dp = new int[value+1];
    dp[0] = 1;
    for(int i=0;i<=value;i++) {
        dp[i]=0;
    }
    dp[0]=1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<=value;j++) {
            if (coins[i] <= j)
                dp[j] += dp[j-coins[i]];
        }
    }
    for(int i=0;i<=value;i++) {
        cout<<dp[i]<<",";
    }
    return dp[value];
}

// int minCoinChangeTopDown(int *coins, int value, int n, int *dp) {
//     if(value<0) {
//         return INT_MAX;
//     }
//     if(value==0) {
//         dp[0] = 0;
//         return 0;
//     }
//     if(dp[value]!=0) {
//         return dp[value];
//     }
//     int currentVal = INT_MAX;
//     for(int i=0;i<n;i++) {
//         currentVal = min(currentVal, minCoinChangeTopDown(coins, value-coins[i], n, dp));
//     }

//     dp[value] = (currentVal==INT_MAX)?-1:1+currentVal;
//     return dp[value];
// }
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,s;
    cin>>n>>s;
    int *coins = new int[n];
    for(int i=0;i<n;i++) {
        cin>>coins[i];
    }
    // int *dp = new int[1005];
    cout<<CoinChangeBottomUp(coins, s, n);
    return 0;
}
