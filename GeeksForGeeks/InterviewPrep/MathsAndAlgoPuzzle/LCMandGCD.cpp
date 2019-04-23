#include <iostream>
#define ll long long int
using namespace std;

ll gcd(ll a, ll b) {
	if(b==0) return a;
	return gcd(b, a%b);
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		ll a, b;
		cin>>a>>b;
		ll gcd_ = gcd(a, b);
		ll lcm = a*b/gcd_;
		cout<<lcm<<" "<<gcd_<<endl;
	}
	return 0;
}
