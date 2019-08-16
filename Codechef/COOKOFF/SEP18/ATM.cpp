#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n;
		long long int k;
		cin>>n>>k;
		for(int i=0;i<n;i++) {
			long long int num;
			cin>>num;
			if(k>=num) {
				cout<<"1";
				k-=num;
			} else {
				cout<<"0";
			}
		}
		cout<<"\n";
	}
	return 0;
}
