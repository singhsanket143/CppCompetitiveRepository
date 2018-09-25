#include <iostream>
#define ll long long int 
using namespace std;


void multiply(ll A[2][2], ll M[2][2]) {
	ll fvalue = A[0][0] * M[0][0] + A[0][1] * M[1][0];
	ll svalue = A[0][0] * M[1][0] + A[0][1] * M[1][1];
	ll tvalue = A[1][0] * M[0][0] + A[1][1] * M[1][0];
	ll lvalue = A[1][0] * M[0][1] + A[1][1] * M[1][1];
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
		ll M[2][2] = {{0,1}, {1,4}};
		multiply(A, M);
	}
}
ll nthevenfib(ll n) {
	ll A[2][2] = {{0,1}, {1,4}};
	if(n==0) {
		return 0;
	}
    if(n==1) {
        return 2;
    }
	power(A, n-1);
	ll f[2] = {0,2};
	return A[1][0]*f[0]+A[1][1]*f[1];
}




int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, t;
	cin>>t;
	while(t--) {
		cin>>n;
		ll f0=0, f1=2;
		ll f = 4*f1+f0;// f(n) = 4*f(n-1) + f(n-2);
		ll sum=2;
		while(f<=n) {
			sum+=f;
			f0=f1;
			f1=f;
			f = 4*f1+f0;
		}
		cout<<sum<<endl;

	}
	
	return 0;
}
