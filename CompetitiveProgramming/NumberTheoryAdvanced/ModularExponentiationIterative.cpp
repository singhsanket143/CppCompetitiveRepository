#include <iostream>
#define ll long long int
using namespace std;

ll modIterative(ll a, ll b, ll c) {
	ll ans = 1;
	while(b!=0) {
		if((b&1)==1) {
			ans = ((ans%c) * (a%c))%c;
		}
		a = ((a%c)*(a%c))%c;
		b >>= 1;
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	cout<<modIterative(2, 6, 5);
	return 0;
}
