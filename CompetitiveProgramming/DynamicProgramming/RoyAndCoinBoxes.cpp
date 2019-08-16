#include <iostream>
#define ll long long int
using namespace std;
ll start[1000002], endi[1000002], temp[1000002], coins[1000002];
int main(int argc, char const *argv[])
{
	int n, m;
	cin>>n>>m;
	for(int i = 0; i < 1000002; i++) {
		coins[i] = 0;
		endi[i] = 0;
		start[i] = 0;
		temp[i] = 0;
	}
	while(m--) {
		int l, r;
		cin>>l>>r;
		start[l]++;
		endi[r]++;
	}
	temp[1] = start[1];
	for(int i=2;i<=n;i++) {
		temp[i] = start[i] - endi[i-1] + temp[i-1];
	}
	
	for(int i=1;i<=n;i++) {
		coins[temp[i]]++;
	}
	for(int i=n-1;i>=0;i--) {
		coins[i] = coins[i]+coins[i+1];
	}
	int q;
	cin>>q;
	while(q--) {
		int r;
		cin>>r;
		cout<<coins[r]<<endl;
	}
	return 0;
}
