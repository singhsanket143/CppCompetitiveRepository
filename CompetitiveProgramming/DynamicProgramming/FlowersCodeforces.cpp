#include <iostream>
#define mod 1000000007
using namespace std;

int* flowers(int n, int k) {
	int *dp = new int[100005];
	dp[0]= 1;
	
	for(int i=1;i<=100000;i++) {
		dp[i] = dp[i-1];
		if(i>=k)
			dp[i] = ((dp[i-1]%mod)+(dp[i-k]%mod))%mod;
	}
	for(int i=1;i<=100000;i++) {
		dp[i]= ((dp[i]%mod)+(dp[i-1]%mod))%mod;
	}
	return dp;
}

int main(int argc, char const *argv[])
{
	int n, k;
	cin>>n>>k;
	int *dp = flowers(n, k);
	while(n--) {
		int a, b;
		cin>>a>>b;
		cout<<(dp[b]-dp[a-1]+mod)%mod<<endl;
	}
	return 0;
}
