#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for(int i=1;i<=n/2+1;i++) {
		int space = n/2-i+1;
		while(space--) {
			cout<<" ";
		}
		for(int j=1;j<=2*i-1;j++) {
			cout<<j;
		}
		cout<<endl;
	}
	for(int i=n/2;i>=1;i--) {
		int space = n/2-i+1;
		while(space--) {
			cout<<" ";
		}
		for(int j=1;j<=2*i-1;j++) {
			cout<<j;
		}
		cout<<endl;
	}
	return 0;
}
