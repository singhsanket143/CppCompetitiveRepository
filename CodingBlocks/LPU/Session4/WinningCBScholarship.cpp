#include <iostream>
#include<stdio.h>
#define ll long long int
using namespace std;

bool check(ll n, ll m, ll x, ll y, ll ans) {
	return ((n-ans)*y + m) >= ans*x;
}

int main(int argc, char const *argv[])
{
	ll n,m,x,y;
	scanf("%lld %lld %lld %lld", &n, &m, &x, &y);
	ll start = 1, end = n;
	ll ans = -1;
	while(start <= end) {
		ll mid = (start+end)/2;
		



		if(check(n,m,x,y, mid)) {
			start = mid+1;
			ans = mid;
		} else {
			end = mid-1;
		}
	}
	cout<<ans;
	return 0;
}