#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Triplet {
public:
	ll x;
	ll y;
	ll gcd;
};

Triplet gcdExtendedEucld(ll a, ll b) {
	if(b==0) {
		Triplet myans;
		myans.gcd = a;
		myans.x = 1;
		myans.y = 0;
		return myans;
	}
	Triplet smallans = gcdExtendedEucld(b, a%b);
	Triplet myans;
	myans.gcd = smallans.gcd;
	myans.x = smallans.y;
	myans.y = (smallans.x - ((a/b)*(smallans.y)));
	return myans;
}

ll modInverse(ll a, ll m) {
	ll x = gcdExtendedEucld(a, m).x;
	return (x%m + m)%m;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int a,b,d;
		cin>>a>>b>>d;
		ll g = gcdExtendedEucld(a,b).gcd;
		if(d%g!=0) {
			cout<<"0"<<endl;
			continue;
		}
		if(d==0) {
			cout<<"1"<<endl;
			continue;
		}
		a/=g;
		b/=g;
		d/=g;
		ll y1 = ((d%a)*modInverse(b,a))%a;
		ll firstValue = d/b;
		if(d < y1*b) {
			cout<<"0"<<endl;
			continue;
		} else {
			ll n = (firstValue - y1)/a;
			cout<<(n+1)<<endl;
		}
	}
	return 0;
}
