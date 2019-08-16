#include <iostream>
using namespace std;
#define mod 1000000007
long long int friendsPairingBottomUp(int n) {
	long long int *dp = new long long int[n+1]();
	for(int i=0;i<=n;i++) {
		if(i<=2) dp[i] = i;
		else dp[i] = ((dp[i-1]%mod) + (((i-1)%mod) * (dp[i-2]%mod))%mod)%mod;
	}
	long long int retval = dp[n];
	delete [] dp;
	return retval;
}

int friendsPairingTopDown(int n, int *dp) {
	if(n==0) return 0;
	if(n==1) return 1;
	if(n==2) return 2;

	if(dp[n] != 0) return dp[n];
	int val = friendsPairingTopDown(n-1, dp) + (n-1)*friendsPairingTopDown(n-2, dp);
	dp[n] = val;
	return val;
}

int main(int argc, char const *argv[])
{
    int t; cin>>t;
    while(t--) {
	int n;
	cin>>n;
	int *dp = new int[n+1]();
	// cout<<friendsPairingTopDown(n, dp);
	cout<<friendsPairingBottomUp(n)<<"\n";
}
	return 0;
}
