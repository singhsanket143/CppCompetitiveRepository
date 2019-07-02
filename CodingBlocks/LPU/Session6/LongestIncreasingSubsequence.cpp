#include <iostream>
using namespace std;

int LIS(int n, int *arr, int *dp) {
	for(int i=1;i<n;i++) {
		for(int j=0;j<i;j++) {
			if(arr[i]> arr[j]) {
				dp[i] = max(dp[i], 1+dp[j]);
			}
		}
	}
	int result = 1;
	for(int i=0;i<n;i++) {
		if(dp[i] > result) result = dp[i];
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	int *dp = new int[n];
	for(int i=0;i<n;i++) {
		dp[i] = 1;
	}
	cout<<LIS(n, arr, dp);
	return 0;
}
