#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int temp = n;
	for(int i=1;i<=n/2 + 1;i++) {
		int space = n/2 - i + 1;
		while(space > 0) {
			cout<<" ";
			space--;
		}
		for(int j=0;j<2*i-1;j++) {
			cout<<"*";
		}
		cout<<endl;
	}
	for(int i=n/2;i>=1;i--) {
		int space = n/2 - i + 1;
		while(space > 0) {
			cout<<" ";
			space--;
		}
		for(int j=0;j<2*i-1;j++) {
			cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}