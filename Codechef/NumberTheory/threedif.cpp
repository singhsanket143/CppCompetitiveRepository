#include <iostream>
#include <algorithm>
#define ll long long int
#define mod 1000000007
using namespace std;
int main(int argc, char const *argv[])
{
	cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
	int t;
	cin>>t;
	ll arr[3];
	ll a,b,c;
	while(t--) {
		cin>>arr[0]>>arr[1]>>arr[2];
		sort(arr, arr+3);
		a = arr[0];
		b = arr[1]-1;
		c = arr[2]-2;
		if(a==0 or b==0 or c==0) {
			cout<<0<<"\n";
		} else {
			ll ans = ((a%mod)*(b%mod))%mod;
			ans = ((ans%mod)*(c%mod))%mod;
			cout<<ans<<"\n";
		}
	}
	return 0;
}
