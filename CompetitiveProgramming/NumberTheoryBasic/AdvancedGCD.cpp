#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;
	while(t--) {
		ll a;
		cin>>a;
		string b;
		cin>>b;
      	if(a==0) {
          cout<<b<<endl;
          continue;
        }
		ll num = 0;
		for(int i=0;i<b.size();i++) {
			num = (((num%a)*(10%a))%a + (b[i]-'0')%a)%a;
		}
		cout<<(__gcd(num,a))<<endl;
	}
	return 0;
}
