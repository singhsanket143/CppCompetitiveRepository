// Problem Link - https://www.codechef.com/problems/FENCE
/* By Sanket Singh */
#include<bits/stdc++.h>
#define ll 				long long int
#define mod             1000000007
#define inf             1e18
#define um 				unordered_map
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
	um<int, um<int, int> > mp;
	int t;
	cin>>t;
	while(t--) {
		ll n, m, k, x, y;
		cin>>n>>m>>k;
		ll ans = 0;
		int dx[] = {0, 0, -1, 1};
		int dy[] = {-1, 1, 0, 0};
		while(k--) {
			cin>>x>>y;
			for(int i = 0; i < 4; i++) {
				ans += mp[x+dx[i]][y+dy[i]] ? -1 : 1;
			}
			mp[x][y] = 1;
		}
		mp.clear();
		cout<<ans<<"\n";
	}
	return 0;
}
