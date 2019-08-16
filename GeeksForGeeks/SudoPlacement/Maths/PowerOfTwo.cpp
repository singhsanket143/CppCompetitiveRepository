#include <iostream>
#define ll long long int
using namespace std;

ll countOnes(ll n){
	ll count = 0;
	while(n) {
		n=n&(n-1);
		count++;
	}
	return count;
}
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--) {
	ll n;
	cin>>n;
	ll x=countOnes(n);
	if(x==1) {
		cout<<"YES"<<endl;
	} else {
		cout<<"NO\n";
	}
    }
	return 0;
}
