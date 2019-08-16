#include <iostream>
#include "cstring"
using namespace std; 

int memo[1000];

int maxProfit_bottomup(int *arr, int totalLen) {
	int dp[1000] = {0};
	for(int length = 1; length <= totalLen; length++) {
		for(int cut = 1; cut <= length; cut++) {
			dp[length] = max(dp[length], arr[cut] + dp[length - cut]);
		}
	}
	return dp[totalLen];
}

int maxProfit_todown(int arr[], int totalLen) {
	if(totalLen <= 0) {
		return 0;
	}
	if(memo[totalLen] != -1) {
		return memo[totalLen];
	}
	int result = 0;
	for(int i=1;i<=totalLen;i++) {
		int currResult = arr[i] + maxProfit_todown(arr, totalLen - i);
		if(result < currResult) result = currResult;
	}
	memo[totalLen] = result;
	return memo[totalLen];
}

int maxProfit(int arr[], int totalLen) {
	if(totalLen <= 0) {
		return 0;
	}

	int result = 0;
	for(int i=1;i<=totalLen;i++) {
		int currResult = arr[i] + maxProfit(arr, totalLen - i);
		if(result < currResult) result = currResult;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int totalLen;
	cin>>totalLen;
	int rod[totalLen];
	for(int i=1;i<=totalLen;i++) {
		cin>>rod[i];
	}
	memset(memo, -1, sizeof(memo));
	int ans = maxProfit_bottomup(rod, totalLen);
	cout<<ans;
	return 0;
}
