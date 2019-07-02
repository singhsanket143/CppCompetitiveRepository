#include <iostream>
using namespace std;

int solutionBottomUp(int n, int m, int **arr, int **dp) {
	// Base case
	for(int i=0;i<m;i++) {
		dp[0][i] = arr[0][i];
	}
	for(int i=0;i<n;i++) {
		dp[i][0] = arr[i][0];
	}

	for(int i=1;i<n;i++) {
		for(int j=1;j<m;j++) {
			if(arr[i][j] == 0) dp[i][j] = 0;
			else {
				dp[i][j] = 1+min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
			}
		}
	}
	int count = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(dp[i][j] > count) count = dp[i][j];
		}
	}
	return count;
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
			dp[i][j] = 0;
			cin>>arr[i][j];
		}
	}
	cout<<solutionBottomUp(n, m, arr, dp);
	return 0;
}
