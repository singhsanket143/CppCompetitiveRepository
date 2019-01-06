#include <iostream>
#define mod 1000000007
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n, m;
		cin>>n>>m;
		int *dp = new int[n+1];
		dp[0] = 1;
		for(int i=1;i<=n;i++) {
			dp[i] = dp[i-1];
			dp[i]+=((i-m)>=0)?dp[i-m]:0;
			dp[i]%=mod;
		}
		cout<<dp[n]<<endl;
		delete [] dp;
	}

	return 0;
}
