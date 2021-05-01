// Problem Link - 
/* By Sanket Singh */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

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
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	ll q;
	cin>>q;
	vector<bool> visited(500005, false);
	ll answer = 0;
	ll count = 1; // order of adding queries
	priority_queue<pair<ll, ll> > p1, p2, p3, p4;
	// p1->(xi+yi), p2->(xi-yi), p3->(-xi+yi), p4->(-xi-yi)
	while(q--) {
		char ch;
		cin>>ch;
		if(ch == '+') {
			// O(logn)
			ll x, y;
			cin>>x>>y;
			x = x^answer;
			y = y^answer;
			p1.push(mp(x+y, count));
			p2.push(mp(x-y, count));
			p3.push(mp(-x+y, count));
			p4.push(mp(-x-y, count));
			count++;
		} else if(ch == '-') {
			//O(1)
			ll n;
			cin>>n;
			n = n^answer;
			visited[n] = true;
		} else {
			ll x, y;
			cin>>x>>y;
			x = x^answer;
			y = y^answer;
			ll result = INT_MIN;
			while(not p1.empty() and visited[p1.top().ss]) p1.pop();
			while(not p2.empty() and visited[p2.top().ss]) p2.pop();
			while(not p3.empty() and visited[p3.top().ss]) p3.pop();
			while(not p4.empty() and visited[p4.top().ss]) p4.pop();
			if(not p1.empty()) {
				result = max(result, p1.top().ff - (x+y));
			}
			if(not p2.empty()) {
				result = max(result, p2.top().ff - (x-y));
			}
			if(not p3.empty()) {
				result = max(result, p3.top().ff - (-x+y));
			}
			if(not p4.empty()) {
				result = max(result, p4.top().ff - (-x-y));
			}
			cout<<result<<endl;
			answer = result;
		}
	}

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
