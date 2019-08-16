#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int temp = n;
	for(int i=1;i<=n/2+1;i++) {
		for(int j=1;j<=i;j++) {
			cout<<"*";
		}
		cout<<endl;
	}
	for(int j=n/2;j>=1;j--) {
		int v = j;
		while(v--) {
			cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}