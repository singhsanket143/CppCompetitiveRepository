#include <bits/stdc++.h>
using namespace std;
int dp[100][100][100];
int lcsTopDown(string str1, string str2, string str3, int m, int n, int o) { 
	if(m==-1 or n==-1 or o==-1) {
		return 0;
	}
	if(dp[m][n][o]!=-1) {
		return dp[m][n][o];
	}
	if(str1[m]==str2[n] and str2[m]==str3[o]) {
		return dp[m][n][o] = 1+lcsTopDown(str1, str2, str3, m-1, n-1, o-1);
	} else {
		return dp[m][n][o] = max(lcsTopDown(str1, str2, str3, m, n, o-1),max(lcsTopDown(str1, str2, str3, m-1, n, o), lcsTopDown(str1, str2, str3, m, n-1, o)));
	}
}

int lcsBottomUp(string str1, string str2, string str3, int m, int n, int o) {
	int dp[m+1][n+1][o+1];
	memset(dp, 0,sizeof(dp)); 
	for(int i=0;i<=m;i++) {
		for(int j=0;j<=n;j++) {
			for(int k=0;k<=o;k++) {
				if(i==0 or j==0 or k==0) dp[i][j][k] = 0;
				else if(str1[i-1]==str2[j-1] and str2[j-1]==str3[k-1]) dp[i][j][k] = 1+dp[i-1][j-1][k-1];
				else dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
			}
		}
	}
	return dp[m][n][o];
}

int main(int argc, char const *argv[])
{
	string str1, str2, str3;
	int t; cin>>t;
	while(t--) {
	int m, n, o; cin>>m>>n>>o;
	cin>>str1>>str2>>str3;
	
// 	memset(dp, -1,sizeof(dp)); 
	cout<<lcsBottomUp(str1, str2, str3, m, n, o)<<endl;
	}
	return 0;
}
