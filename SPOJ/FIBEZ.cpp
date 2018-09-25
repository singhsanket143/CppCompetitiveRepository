#include <stdio.h>
#define mod 1000000007
#define ll long long int
using namespace std;

ll M[2][2] = {{0,1}, {1,1}};
void multiply(ll A[2][2], ll M[2][2]) {
	int fvalue = ((A[0][0] * M[0][0])%mod + (A[0][1] * M[1][0])%mod)%mod;
	int svalue = ((A[0][0] * M[1][0])%mod + (A[0][1] * M[1][1])%mod)%mod;
	int tvalue = ((A[1][0] * M[0][0])%mod + (A[1][1] * M[1][0])%mod)%mod;
	int lvalue = ((A[1][0] * M[0][1])%mod + (A[1][1] * M[1][1])%mod)%mod;
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
	if(n&1) {
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
	return ((A[1][0] * f[0])%mod +(A[1][1] * f[1])%mod)%mod;
}

int main()
{
	ll t;
	scanf("%lld", &t);
	while(t--) {
		ll n;
		scanf("%lld", &n);
		printf("%lld\n", fib(n));
	}
	
	return 0;
}
