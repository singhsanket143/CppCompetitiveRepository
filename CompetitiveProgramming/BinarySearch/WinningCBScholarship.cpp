#include <iostream>
#define ll long long int
using namespace std;

bool check(int n, int m, int x, int y, ll ans) {
	if((n-ans)*y + m >= x*ans) {
		return true;
	} else {
		return false;
	}
}


int main(int argc, char const *argv[])
{
	ll n, m , x, y;
	cin>>n>>m>>x>>y;
	ll lo = 1, hi = n;
	ll result = 0;
	while(lo<=hi) {
		ll mid = (lo+hi)/2;
		if(check(n, m, x, y, mid)) {
			result = mid;
			lo = mid+1;
		} else {
			hi = mid-1;
		}

	}
	cout<<result;
	return 0;
}
