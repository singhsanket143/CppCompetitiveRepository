#include <iostream>
#include <cstring>
using namespace std;

int memo[1000][1000];

int wineYear_bottomup(int *arr, int n) {
	int **dp = new int*[n];
	for(int i=0;i<n;i++) {
		dp[i] = new int[n];
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			dp[i][j]=0;
		}
	}
	for(int i = 0; i < n; i++) {
		dp[i][i] = arr[i]*n;
	}
	int year = n-1;
	for(int window = 1; window < n; window++) {
		int start = 0;
		for(;start + window < n; start++) {
			dp[start][start+window] = max(arr[start]*year + dp[start+1][start+window], arr[start+window]*year + dp[start][start+window-1]);
		}
		year--;
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	int result = dp[0][n-1];
	for(int i=0;i<n;i++) {
		delete [] dp[i];
	}
	delete [] dp;
	return result;
}

int wineYear_topdown(int *arr, int si, int ei, int year) {
	if(si > ei) {
		return 0;
	}
	if(memo[si][ei] != -1) {
		return memo[si][ei];
	}
	int result_from_front = arr[si] *year + wineYear_topdown(arr, si+1, ei, year+1);
	int result_from_end = arr[ei] *year + wineYear_topdown(arr, si, ei - 1, year+1);
	memo[si][ei] = max(result_from_end, result_from_front);
	return memo[si][ei];
}

int wineYear(int *arr, int si, int ei, int year) {
	if(si>ei) {
		return 0;
	}
	int result_from_front = arr[si] *year + wineYear(arr, si+1, ei, year+1);
	int result_from_end = arr[ei] *year + wineYear(arr, si, ei - 1, year+1);
	return max(result_from_end, result_from_front);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	memset(memo, -1, sizeof(memo));
	cout<<wineYear_topdown(arr, 0, n-1, 1)<<endl;
	cout<<wineYear_bottomup(arr, n);
	return 0;
}
