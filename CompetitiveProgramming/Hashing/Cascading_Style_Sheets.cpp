// Problem Link - https://www.codechef.com/problems/CSS2
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
	ump<int, ump<int, pair<int, int> > > mp; // id, attr, val, pri
	int n, m;
	cin>>n>>m;
	while(n--) {
		int id, attr, val, pri;
		cin>>id>>attr>>val>>pri;
		if(mp.find(id) == mp.end()) {
			mp[id][attr] = make_pair(val, pri);
		} else {
			if(mp[id].find(attr) == mp[id].end()) {
				mp[id][attr] = make_pair(val, pri);
			} else {
				pair<int, int> pii = mp[id][attr];
				if(pii.ss < pri) {
					mp[id][attr] = make_pair(val, pri);
				} else if(pri < pii.ss) continue;
				else {
					mp[id][attr].ff = val;
				}
			}
		}
	}
	while(m--) {
		int id, attr;
		cin>>id>>attr;
		cout<<mp[id][attr].ff<<endl;
	}

	return 0;
}
