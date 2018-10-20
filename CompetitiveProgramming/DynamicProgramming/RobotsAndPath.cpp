#include <iostream>
#define mod 1000000007
using namespace std;
long long dp[1005][1005];
long long path(int row, int col) {

	if(dp[0][0] == -1) {
		return 0;
	}	
	for(int i=0;i<col;i++) {
		if(dp[0][i] == -1) {
			break;
		}
		dp[0][i] = 1;
	}
	for(int i=0;i<row;i++) {
		if(dp[i][0] == -1) {
			break;
		}
		dp[i][0] = 1;
	}
	for(int i=1;i<row;i++) {
		for(int j=1;j<col;j++) {
			if(dp[i][j] == -1) {
				continue;
			}
			dp[i][j] = 0;
			if(dp[i][j-1]!=-1)
				dp[i][j] = dp[i][j-1]%mod;
			if(dp[i-1][j]!=-1) 
				dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
		}
	}
	if(dp[row-1][col-1] == -1) {
		return 0;
	}
	return dp[row-1][col-1];
}

int main(int argc, char const *argv[])
{
	int n,m,k;
	cin>>n>>m>>k;
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			dp[i][j]=0;
		}
	}
	while(k--) {
		int x,y;
		cin>>x>>y;
		dp[x-1][y-1] = -1;
	}
	cout<< path(n, m);
	return 0;
}
