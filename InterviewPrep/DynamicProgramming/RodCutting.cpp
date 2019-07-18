#include <iostream>
using namespace std;

int rodCut(int *price, int n) {
	int *dp = new int[n+1];
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		int max_val = INT_MIN;
		for(int j = 0; j < i; j++) {
			max_val = max(max_val, price[j] + dp[i-j-1]);
		}
		dp[i] = max_val;
	}
	return dp[n];
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	cout<<rodCut(arr, n);
	return 0;
}
