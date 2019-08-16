#include <iostream>
using namespace std;
int minCoinChangeBU(int *coins, int k, int v) {
		int *dp = new int[v+1];
        for(int i=0;i<=v;i++) {
            dp[i] = INT_MAX;
        }
        dp[0] = 0;
        for(int i=1;i<=v;i++) {
            for(int j = 0; j < k; j++) {
                if(coins[j]<=i){
                    int ans = dp[i-coins[j]];
                    if(dp[i-coins[j]] == INT_MAX) {
                        // nothing
                    } else {
                        ans = 1+dp[i-coins[j]];
                    }
                    dp[i] = min(dp[i], ans);
                }
            }
        }
        return dp[v]==INT_MAX?-1:dp[v];
}

int minCoinChangeTD(int *coins, int k, int v, int *dp) {
	// Base case
	if(v<0) {
		return INT_MAX;
	}
	if(v==0) return 0;
	if(dp[v] != -1) {
		return dp[v];
	}
	int result = INT_MAX;
	for(int i=0;i<k;i++) {
		int recResult = minCoinChangeTD(coins, k, v-coins[i], dp);
		if(recResult == INT_MAX) {
			// nothing
		} else {
			recResult = 1 + recResult;
		}
		result = min(result, recResult);
	}
	dp[v] = result;
	return result;
}

int minCoinChange(int *coins, int k, int v) {
	// Base case
	if(v<0) {
		return INT_MAX;
	}
	if(v==0) return 0;

	int result = INT_MAX;
	for(int i=0;i<k;i++) {
		int recResult = minCoinChange(coins, k, v-coins[i]);
		if(recResult == INT_MAX) {
			// nothing
		} else {
			recResult = 1 + recResult;
		}
		result = min(result, recResult);
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int k;
	cin>>k;
	int *coins = new int[k];
	for(int i=0;i<k;i++) {
		cin>>coins[i];
	}
	int v;
	cin>>v;
	int *dp = new int[v+1];
	for(int i=0;i<=v;i++) {
		dp[i] = -1;
	}
	cout<<minCoinChangeBU(coins, k, v)<<endl;
	cout<<minCoinChangeTD(coins, k, v, dp)<<endl;
	cout<<minCoinChange(coins, k, v);
	return 0;
}
