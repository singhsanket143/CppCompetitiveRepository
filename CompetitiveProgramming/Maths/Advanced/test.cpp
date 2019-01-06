#include <iostream>
#define ll long long int 
using namespace std;


void multiply(ll a[3][3], ll b[3][3]) {
	int mul[3][3]; 
    for (int i = 0; i < 3; i++) 
    { 
        for (int j = 0; j < 3; j++) 
        { 
            mul[i][j] = 0; 
            for (int k = 0; k < 3; k++) 
                mul[i][j] += a[i][k]*b[k][j]; 
        } 
    } 
  
    // storing the muliplication resul in a[][] 
    for (int i=0; i<3; i++) 
        for (int j=0; j<3; j++) 
            a[i][j] = mul[i][j];
}

void power(ll A[3][3], ll n) {
	if(n==0 or n==1) {
		return;
	}
	power(A, n/2);
	multiply(A, A);
	if(n%2!=0) {
		ll M[3][3] = {{0,1,0},{2,1,1},{0,0,1}};
		multiply(A, M);
	}
}
ll fib(ll n) {
	ll A[3][3] = {{0,1,0},{2,1,1},{0,0,1}};
	if(n==0) {
		return 0;
	}
	power(A, n-1);
	ll f[3] = {0,1,3};
	return A[1][0]*f[0]+A[1][1]*f[1]+A[1][2]*f[2];
}



int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	if(n==1){
		cout<<0;
	} else if(n==2) {
		cout<<1;
	} else if(n==3) {
		cout<<4;
	} else 
		cout<<fib(n-1);
	return 0;
}
