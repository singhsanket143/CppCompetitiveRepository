#include <iostream>
using namespace std;

int lis(int *arr, int n) {
	int dp[1000];
	for(int i = 0; i < n; i++) dp[i] = 1;
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < i; j++) {
			if(arr[j]<=arr[i]) {
				dp[i] = max(dp[i], 1+dp[j]);
			}
		}
	}
	int result = -1;
	for(int i = 1; i < n; i++) {
		result = (dp[i] > result)?dp[i]:result;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
