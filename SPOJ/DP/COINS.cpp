#include <iostream>
#include <stdio.h>
#include <unordered_map>
using namespace std;
#define ll long long int
unordered_map<int, ll> dp;
ll fun(int n) {
	if(n==0) return 0;
	if(dp[n]!=0) return dp[n];
	ll ans=fun(n/2)+fun(n/3)+fun(n/4);
	if(ans>n)
		dp[n]=ans;
	else
		dp[n]=n;
	return dp[n];
}

int main(int argc, char const *argv[])
{
	/* code */
	int n;
	while(scanf("%d", &n)==1) printf("%lld\n", fun(n));
	return 0;
}
