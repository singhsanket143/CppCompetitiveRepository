#include <iostream>
using namespace std;

int knapsack(int W, int *wt, int *val, int n) {
	int dp[2][W+1];
	for(int i=0;i<=W;i++) {
		dp[0][i] = 0;
	}
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=W;j++) {
			if(i==0 or j==0) {
				dp[1][j] = 0;
			}
			if(wt[i-1] > j) {
				dp[1][j] = dp[0][j];
			} else {
				dp[1][j] = max(val[i-1] + dp[0][j-wt[i-1]],
							   dp[0][j]
				);
			}
		}
		for(int j=0;j<=W;j++) 
			dp[0][j] = dp[1][j];
	}
	return dp[1][W];
}

int main(int argc, char const *argv[])
{
	/* code */
	int wt;
	cin>>wt;
	int n;
	cin>>n;

	int vals[n] ;
	int wts[n] ;
	for(int i=0;i<n;i++) {
		cin>>wts[i]>>vals[i];
	}
	
	
	cout<<knapsack( wt, wts, vals,n);
	return 0;
}
