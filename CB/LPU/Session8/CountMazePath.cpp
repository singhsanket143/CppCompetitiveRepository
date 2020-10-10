#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	/* code */
	int n, m;
	cin>>n>>m;
	int **dp = new int*[n];
	for(int i=0;i<n;i++) {
		dp[i] = new int[m];
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	for(int i=1;i<n;i++) {
		dp[i][0] = 1;
	}
	for(int i=1;i<m;i++) {
		dp[0][i] = 1;
	}
	for(int i=1;i<n;i++) {
		for(int j=0;j<m;j++) {
			dp[i][j] = dp[i-1][j]+dp[i][j-1];
		}
	}
	cout<<dp[n-1][m-1];
	return 0;
}
