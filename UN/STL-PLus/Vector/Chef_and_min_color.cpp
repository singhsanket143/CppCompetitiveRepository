// Problem Link - https://www.codechef.com/NOV19B/problems/CAMC
/* By Sanket Singh */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				emplace_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int i=(a);i<=(b);i++) cout<<(arr[i])<<" ";cout<<endl;	
#define token(str,ch)	(std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
	while(t--) {
		int m, n;
		cin>>n>>m;
		vector<pair<ll, int> > v(n);
		loop(i, 0, n-1) {
			cin>>v[i].ff;
			v[i].ss = i%m;
		}
		// for(int i =0 ; i < n; i++) {
		// 	cout<<v[i].ff<<" ";
		// }
		int count = m;
		int right = 0;
		ll ans = INT_MAX;
		sort(v.begin(), v.end());
		vector<int> cnt(m, 0);
		loop(left, 0, n-1) {
			while(right < n and count > 0) {
				count -= cnt[v[right].ss] == 0;
				cnt[v[right].ss]++;
				right++;
			}
			if(count == 0) { // we got m uniq boxes
				ans = min(ans, v[right-1].ff - v[left].ff);
			}
			if(cnt[v[left].ss] > 0) {
				cnt[v[left].ss]--;
			}
			// missing?
			count += cnt[v[left].ss] == 0;
		}
		cout<<ans<<endl;
	}
	return 0;
}
