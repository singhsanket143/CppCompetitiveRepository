#include <iostream>
using namespace std;

int minDistance(string s1, string s2) {
	int n = s1.size();
	int m = s1.size();
	int dp[s1.size()+1][s2.size()+1];
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=m;j++) {
			dp[i][j] = 0;
		}
	}
	for(int i=0;i<=m;i++) {
		dp[0][i] = i;
	} 
	for(int i=0;i<=n;i++) {
		dp[i][0] = i;
	} 
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(s1[i-1]==s2[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = 1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
			}
		}
	}
	return dp[n][m];
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
