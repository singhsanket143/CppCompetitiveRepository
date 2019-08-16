#include <iostream>
using namespace std;

int noOfWaysDp(int n, int k) {
	int **dp = new int*[n+1];
	for(int i=0;i<=n;i++) {
		dp[i] = new int[k+1]();
	}
	for(int i=0;i<=n;i++) {
		dp[i][0] = 0;
	}
	for(int i=0;i<=k;i++) {
		dp[0][i] = 0;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=k;j++) {
			if(j==1 or j==i) {
				dp[i][j] = 1;
			} else {
				dp[i][j] = j*dp[i-1][j] + dp[i-1][j-1];
			}
		}
	}
	return dp[n][k];
}

int noOfWays(int n, int k) {
	if(n==0 or k==0 or k>n) return 0;
	if(k==1 or k==n) return 1;
	return noOfWays(n-1, k)*k + noOfWays(n-1, k-1);
}

int main(int argc, char const *argv[])
{
	int n, k;
	cin>>n>>k;
	cout<<noOfWaysDp(n, k)<<endl;
	cout<<noOfWays(n, k)<<endl;
	return 0;
}
