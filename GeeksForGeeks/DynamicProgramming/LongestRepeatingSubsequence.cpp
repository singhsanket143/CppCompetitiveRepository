#include <iostream>
using namespace std;

int dp[1000][1000];

int longestRepeatingSubBottomUp(string X) {
	int n = X.length();
	int dp[n+1][n+1];
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=n;j++) {
			dp[i][j] = 0;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(X[i-1]==X[j-1] and i!=j) {
				dp[i][j] = dp[i-1][j-1]+1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[n][n];
}

int longestRepeatingSubTopDown(string X, int m, int n) {
	if(m==0 or n==0) {
		return dp[m][n]=0;
	}
	if(dp[m][n]!=-1) {
		return dp[m][n];
	}
	int val;
	if(X[m-1] == X[n-1] and m!=n) {
		val=longestRepeatingSubTopDown(X, m-1, n-1)+1;
	} else {
		val = max(longestRepeatingSubTopDown(X, m-1, n), longestRepeatingSubTopDown(X, m, n-1));
	}
	dp[m][n]=val;
	return val;
}

int main(int argc, char const *argv[])
{
	/* code */
	// memset(dp, -1, sizeof(dp));
	string str;
	cin>>str;
	cout<<longestRepeatingSubBottomUp(str)<<endl;
	return 0;
}
