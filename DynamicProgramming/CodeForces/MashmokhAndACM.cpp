#include <iostream>
using namespace std;
#define mod 1000000007
#define ll unsigned long long
ll n, k, dp[2005][2005];

ll goodSequenceDp2(ll ni, ll ki) {
	if(dp[ni][ki]!=-1) return dp[ni][ki];
	if(ni>n) return 0;
	if(ki==k) {
		// cout<<osf<<endl;
		return 1;
	}
	
	
	ll result = 0;
	for(ll i=1;i*ni<=n;i++) {
		if(i*ni<=n)
			result = ((result%mod) + (goodSequenceDp2(i*ni, ki+1))%mod)%mod;
	}
	return dp[ni][ki]=result%mod;
}

ll goodSequenceDp(int n, int k, int lastDigit, ll dp[][2005]) {
	if(k==0) {
		// cout<<osf<<endl;
		return 1;
	}
	if(dp[n][k]!=-1) return dp[n][k];
	ll result = 0;
	for(int i=n;i>=1;i--) {
		if(lastDigit%i==0)
			result += goodSequenceDp(i, k-1, i, dp)%mod;
	}
	return dp[n][k]=result%mod;
}

int goodSequence(int n, int k, string osf, int lastDigit) {
	if(k==0) {
		cout<<osf<<endl;
		return 1;
	}
	int result = 0;
	for(int i=n;i>=1;i--) {
		if(lastDigit%i==0)
			result+=goodSequence(i, k-1, osf + to_string(i) + " ", i);
	}
	return result;
}

int main(int argc, char const *argv[])
{
	memset(dp, -1, sizeof(dp)); 
	
	cin>>n>>k;
	int lastDigit = 0;
	cout<<goodSequence(n, k, "", lastDigit)<<endl;;
	
	// cout<<goodSequenceDp(n, k, lastDigit, dp);
	// ll re = 0;
	// for(ll i=1;i<=n;i++) {
	// 	re+=goodSequenceDp2(i, 1)%mod;
	// }
	// cout<<re%mod;
	return 0;
}
