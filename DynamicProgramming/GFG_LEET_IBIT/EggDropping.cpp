#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int DP[1005][1005];

int eggDropBUDP(int n, int k) {
	memset(DP, 0, sizeof(DP));
	for(int i=0;i<=k;i++) {
		DP[0][i] = 0;
		DP[1][i] = i;
	}
	for(int i=0;i<=n;i++) {
		DP[i][0] = 0;
		DP[i][1] = 1;
	}
	for(int i = 2; i <= n; i++) {
		for(int j = 2; j <= k; j++) {
			if(i > j) {
				DP[i][j] = DP[i-1][j];
			} else {
				DP[i][j] = INT_MAX;
				for(int x = 1; x <= j; x++) {
					int retval = max(DP[i-1][x-1], DP[i][j-x]);
					if(retval < DP[i][j]) DP[i][j] = retval;
				}
				DP[i][j] = DP[i][j] + 1;
			}
		}
	}
	return DP[n][k];
}

int eggDropTDDP(int n, int k) {
	if(k==0 or k==1) return k;
	if(n==1) return k;
	if(DP[n][k] != -1) return DP[n][k];

	int result = INT_MAX;
	for(int x = 1; x <= k; x++) {
		int retval = max(eggDropTDDP(n-1, x-1), eggDropTDDP(n, k-x));
		if(retval < result) {
			result = retval;
		}
	}
	return DP[n][k] = 1 + result;
}

int eggDrop(int n, int k) {
	if(k==0 or k==1) return k;
	if(n==1) return k;

	int result = INT_MAX;
	for(int x = 1; x <= k; x++) {
		int retval = max(eggDrop(n-1, x-1), eggDrop(n, k-x));
		if(retval < result) {
			result = retval;
		}
	} 
	return 1 + result;
}

int main(int argc, char const *argv[])
{
	int n, k, t;
	cin>>t;
	while(t--) {
	cin>>n>>k;
		// memset(DP, -1, sizeof(DP));
		// cout<<eggDropTDDP(n, k)<<endl; For Top Down DP
		cout<<eggDropBUDP(n, k)<<endl; // For Bottom Up DP
		// cout<<eggDrop(n, k); For Recursive Solution
	}
	return 0;
}
