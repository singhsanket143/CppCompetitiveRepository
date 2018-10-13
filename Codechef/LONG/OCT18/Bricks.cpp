#include <iostream>
#define ll long long int
#define mod 1000000007
using namespace std;
ll memo[1005][1005];

// int bricks(ll n, int k) {
// 	if(k>n) {
// 		memo[n][k] = 0;
// 		return 0;
// 	}
// 	if(k==1) {
// 		memo[n][k] = 2*n;
// 		return 2*n;
// 	}
// 	if(k==n) {
// 		memo[n][k] = 2;
// 		return 2;
// 	}


// }

int main(int argc, char const *argv[])
{
	/* code */
	int t;
	cin>>t;
	for(int i=0;i<=1000;i++) {
		for(int j=0;j<=1000;j++) {
			memo[i][j] = 0;
		}
	}
	for(int i = 1; i <= 1000;i++) {
		memo[0][i-1]=2*i;
	}
	int i=0, j=0;
	for(; i<=1000 and j<=1000; i++, j++) {
		memo[i][j] = 2;
	}
	for(int i=1;i<=1000;i++) {
		for(int j=i+1;j<=1000;j++) {
			memo[i][j] = ((memo[i][j-1]%mod)+(memo[i-1][j-1]%mod)+(memo[i-1][j-2]%mod))%mod;
		}
	}
	while(t--) {
		ll n;
		int k;
		cout<<memo[n][k]<<endl;;
	}
	return 0;
}
