// Problem Link - https://cses.fi/problemset/task/1145
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

void update(vi &lis, vi &tree, ll s, ll e, ll tidx, ll i, ll v) {
	if(s == e) {
		tree[tidx] = v;
		lis[i] = v;
		return;
	}
	ll m = mid(s, e);
	if(i > m) {
		update(lis, tree, m+1, e, 2*tidx+1, i, v);
	} else {
		update(lis, tree, s, m, 2*tidx, i, v);
	}
	tree[tidx] = max(tree[2*tidx], tree[2*tidx+1]);
}

ll query(vi &tree, ll s, ll e, ll tidx, ll l, ll r) {
	if(r < s or l > e) return 0;
	if(s >= l and e <= r) return tree[tidx];
	ll m = mid(s, e);
	ll left = query(tree, s, m, 2*tidx, l, r);
	ll right = query(tree, m+1, e, 2*tidx+1, l, r);
	return max(left, right);
}

bool cmp(pii x, pii y) {
	if(x.ff == y.ff) {
		return x.ss > y.ss;
	}
 	return x.ff < y.ff;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	ll n;
	cin>>n;
	vector<pii> arr(n);
	loop(i, 0, n-1) {
		cin>>arr[i].ff;
		arr[i].ss = i;
	}
	sort(all(arr), cmp);

	vi tree(4*n, 0); // build

	vi lis(n, 0);
	
	loop(i, 0, n-1) {
		ll element = arr[i].ff;
		ll index = arr[i].ss;
		ll res = query(tree, 0, n-1, 1, 0, index);
		update(lis, tree, 0, n-1, 1, index, res+1);
	}
	ll lis_val = -inf;
	loop(i, 0, n-1) {
		lis_val = max(lis_val, lis[i]);
	}
	cout<<lis_val;
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
