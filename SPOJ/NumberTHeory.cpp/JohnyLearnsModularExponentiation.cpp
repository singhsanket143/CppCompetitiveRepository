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
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++) {
		ll a,b,c;
		cin>>a>>b>>c;
		ll ans = modIterative(a, b, c);
		cout<<i<<". "<<ans<<endl;
	}
	return 0;
}
