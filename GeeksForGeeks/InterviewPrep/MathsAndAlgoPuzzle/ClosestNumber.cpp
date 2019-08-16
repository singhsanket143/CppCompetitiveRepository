#include <iostream>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		ll a, b;
		cin>>a>>b;
		int q=a/b;
		int n1 = b*q, n2;
		if(a*b>0) {
			n2=b*(q+1);
		} else {
			n2=b*(q-1);
		}
		if(abs(n-n1)<abs(n-n2)) {
			cout<<n1<<endl;
		} else {
			cout<<n2<<endl;
		}
	}
	return 0;
}
