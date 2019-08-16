#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		int l, r;
		cin>>l>>r;
		int ans=0, maxBits = 0;
		for(int i=l;i<=r;i++) {
			int x = __builtin_popcount(i);
			if(maxBits<x) {
				ans = i;
				maxBits = x;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
