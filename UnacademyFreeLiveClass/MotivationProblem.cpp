// Problem Link - 
/* By Sanket Singh */
#include<bits/stdc++.h>
using namespace std;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

int main(int argc, char const *argv[]) {
	file_i_o();
	int n, q;
	cin>>n>>q;
	vector<int> v(n, 0);
	while(q--) {
		int l, r;
		cin>>l>>r;
		v[l]++;
		if(r+1 < n) {
			v[r+1]--;
		}
	}
	for(int i = 1; i < n; i++) {
		v[i] = v[i] + v[i-1];
	}
	for(auto el: v) {
		cout<<el<<" ";
	}
	return 0;
}
