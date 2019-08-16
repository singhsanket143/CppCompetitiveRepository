#include <iostream>
using namespace std;

long long int lis(int *arr, int n) {
	long long int dp[10000];
	for(int i = 0; i < n; i++) dp[i] = 1;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(arr[j]<arr[i]) {
				dp[i] = max(dp[i], 1+dp[j]);
			}
		}
	}
	long long int result = 0;
	for(int i = 0; i < n; i++) {
		result = (dp[i] > result)?dp[i]:result;
	}
	return result;
}
 
int main(int argc, char const *argv[])
{
	/* code */
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	cout<<lis(arr, n);
	return 0;
}
 
