#include <iostream>
#define ll long long int
#define mod 1000000007
using namespace std;

ll fact(ll n) {
    if(n==0 or n==1) {
        return 1;
    }
	ll result = 1;
	for(int i=1;i<=n;i++) {
		result = ((result%mod) * (i%mod))%mod;
	}
	return result;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		ll s,n;
		cin>>n>>s;
		ll f1 = fact(n-s+1);
		ll f2 = fact(s);
		//cout<<f1<<" "<<f2<<endl;
		cout<<(((f1%mod) * (f2%mod))%mod)<<endl;
	}
	return 0;
}