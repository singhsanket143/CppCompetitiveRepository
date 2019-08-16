#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int five=5;
		int count=0;
		while(five<=n) {
			count+=n/five;
			five*=5;
		}
		cout<<count<<endl;
	}
	return 0;
}
