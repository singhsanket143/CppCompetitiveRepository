#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int x=0;
		for(int i=0;i<n;i++) {
			int num;
			cin>>num;
			x^=num;
		}
		cout<<x<<endl;
	}
	return 0;
}
