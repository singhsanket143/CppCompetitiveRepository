#include <iostream>
#include <cstring>
using namespace std;
int dp[105][105][2];

int adjBitCount(int n, int k, int first) {
	if(n==0) return 0;
	if(n==1) {
		if(k==0) return 1;
		else if(k<0) return 0;
		else return 0;
	}
	if(dp[n][k][first] != -1) {
		return dp[n][k][first];
	}
	int retval = -1;
	if(first == 1) {
		retval = adjBitCount(n-1, k-1, 1) + adjBitCount(n-1, k, 0);
	} else {
		retval = adjBitCount(n-1, k, 1) + adjBitCount(n-1, k, 0);	
	}

	return dp[n][k][first] = retval;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int num, n, k;
		cin>>num>>n>>k;
		memset(dp, -1, sizeof(dp));
		int ans = adjBitCount(n, k, 0);
		ans += adjBitCount(n, k, 1);
		cout<<num<<" "<<ans<<"\n";
	}
	return 0;
}
