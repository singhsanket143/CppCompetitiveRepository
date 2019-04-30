#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[2000][2000];
ll dice(int m, int n, int x) {
    if(n>x) {
        return 0;
    }
	if(n==0 and x==0) {
		return 1;
	}
	if(n==0 and x!=0) {
		return 0;
	}
	if(n!=0 and x==0) {
		return 0;
	}
	if(dp[n][x] != -1) return dp[n][x];
	ll result = 0;
	for(int i=1;i<=m;i++) {
		result += dice(m, n-1, x-i);
	}
	return dp[n][x]=result;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int m, n, x;
		cin>>m>>n>>x;
		memset(dp, -1, sizeof(dp));
		cout<<dice(m, n, x)<<endl;
	}
	return 0;
}
