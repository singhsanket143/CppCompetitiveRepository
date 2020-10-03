// Problem Link - https://www.codechef.com/problems/LGCD
/* By Sanket Singh */
#include<bits/stdc++.h>
#define ll 				long long int
#define mod             1000000007
#define inf             1e18
#define ump				unordered_map
#define mp 				map
#define ff 				first
#define ss 				second
#define loop(i,n) 		for(int i=0;i<(n);i++)
#define DEBUG(x) 		cout << '>' << #x << ':' << x << endl;
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
	int t;
	cin>>t;
	ump<int, int> map;
	while(t--) {
		int n, x;
		cin>>n;
		for(int i = 0; i < n; i++) {
			cin>>x;
			map[x]++;
		}
		ll ans = 0;
		for(auto x: map) {
			if(map.find(2*x.ff) != map.end()) {
				ans+=map[x.ff]*map[2*x.ff];
			}
		}
		cout<<ans<<endl;
		map.clear();
	}
	return 0;
}
