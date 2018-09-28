#include <iostream>
#define ll long long int 
#define mod 1000000007
using namespace std;

void multiply(ll A[2][2], ll M[2][2]) {
	ll fvalue = ((A[0][0] * M[0][0])%mod + (A[0][1] * M[1][0])%mod)%mod;
	ll svalue = ((A[0][0] * M[1][0])%mod + (A[0][1] * M[1][1])%mod)%mod;
	ll tvalue = ((A[1][0] * M[0][0])%mod + (A[1][1] * M[1][0])%mod)%mod;
	ll lvalue = ((A[1][0] * M[0][1])%mod + (A[1][1] * M[1][1])%mod)%mod;
	A[0][0] = fvalue;
	A[0][1] = svalue;
	A[1][0] = tvalue;
	A[1][1] = lvalue;
}

void power(ll A[2][2], ll n) {
	if(n==0 or n==1) {
		return;
	}
	power(A, n/2);
	multiply(A, A);
	if(n%2!=0) {
		ll M[2][2] = {{0,1}, {1,1}};
		multiply(A, M);
	}
}
ll fib(ll n) {
	ll A[2][2] = {{0,1}, {1,1}};
	if(n==0) {
		return 0;
	}
	power(A, n-1);
	ll f[2] = {0,1};
	return ((A[1][0]*f[0])%mod + (A[1][1]*f[1])%mod)%mod;
}
int main(int argc, char const *argv[])
{
	cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
	int t;
	cin>>t;
	ll n;
	while(t--) {
		cin>>n;
		if(n==1) {
			cout<<2<<"\n";
			continue;
		} else if(n==0) {
			cout<<0<<"\n";
			continue;
		}
		ll a = fib(n+3);
		
		cout<<(a)<<"\n";
	}
	return 0;
}
