#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int a, b;
		cin>>a>>b;
		if(a==b) cout<<"1\n";
		if(a>b and b!=1) cout<<"0\n";
		if(a==1 and b!=1) {
			cout<<"0\n";
		} else if(a==0) {
			cout<<"0\n";
		} else {
			while(b>1) {
				if(b%a==0) {
					b=b/a;
				} else {
					break;
				}
			}
			if(b==1) cout<<"1\n";
			else cout<<"0\n";
		}
	}
	return 0;
}
