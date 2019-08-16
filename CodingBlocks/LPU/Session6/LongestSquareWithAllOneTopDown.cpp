#include <iostream>
using namespace std;

int solutionTopDown(int **arr, int n, int m, int **dp, int i, int j) {
	if(dp[i][j]!=-1) {
		return dp[i][j];
	}
	int call1 = solutionTopDown(arr, n, m, dp, i-1, j-1);
	int call2 = solutionTopDown(arr, n, m, dp, i-1, j);
	int call3 = solutionTopDown(arr, n, m, dp, i, j-1);
	if(arr[i][j] == 0) {
		dp[i][j] = 0;
		return 0;
	}
	int result = min(call1, min(call2, call3));
	dp[i][j] = result+1;
	return dp[i][j];
}

int main(int argc, char const *argv[])
{
	int n, m;
	cin>>n>>m;
	int **arr = new int*[n];
	int **dp = new int*[n];
	for(int i=0;i<n;i++) {
		dp[i] = new int[m];
		arr[i] = new int[m];
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			dp[i][j] = -1;
			cin>>arr[i][j];
		}
	}

	for(int i=0;i<m;i++) {
		dp[0][i] = arr[0][i];
	}
	for(int i=0;i<n;i++) {
		dp[i][0] = arr[i][0];
	}
	solutionTopDown(arr, n, m, dp, n-1, m-1);
	int count = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(dp[i][j] > count) count = dp[i][j];
		}
	}
	cout<<count;
	return 0;
}
