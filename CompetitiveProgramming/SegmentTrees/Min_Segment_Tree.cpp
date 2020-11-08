// Problem Link - https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B
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
void build(ll *arr, ll *segtree,int s, int e, int tidx) {
	// base case
	if(s == e) {
		segtree[tidx] = arr[s];
		return;
	}
	int mid = (s+e)/2;
	build(arr, segtree, s, mid, 2*tidx);
	build(arr, segtree, mid+1, e, 2*tidx+1);

	// self work
	segtree[tidx] = min(segtree[2*tidx],segtree[2*tidx+1]);
}

void update(ll *arr, ll *tree, int s, int e, int tidx, int idx, ll val) {
	if(s==e) {
		arr[idx] = val;
		tree[tidx] = val;
		return;
	}
	int mid = (s+e)/2;
	if(idx>mid) {
		update(arr, tree, mid+1, e, 2*tidx+1, idx, val);
	} else {
		update(arr, tree, s, mid, 2*tidx, idx, val);
	}
	tree[tidx] = min(tree[2*tidx],tree[2*tidx+1]);
}

ll query(ll *tree, ll s, int e, int tidx, int left, int right) {
	if(s > right or e < left) {
		// complete outside
		return INT_MAX;
	}
	if(s >= left and e <= right) {
		// complete inside
		return tree[tidx];
	}

	int mid = (s+e)/2;
	ll a1 = query(tree, s, mid, 2*tidx, left, right);
	ll a2 = query(tree, mid+1, e, 2*tidx+1, left, right);
	return min(a1,a2);
}

int main(int argc, char const *argv[]) {
	file_i_o();
	int n;
	cin>>n;
	int q;
	cin>>q;
	ll *arr = new ll[n];
	loop(i, 0, n-1) {
		cin>>arr[i];
	}
	ll *segtree = new ll[4*n];
	build(arr, segtree, 0, n-1, 1);
	
	while(q--) {
		int type;
		cin>>type;
		if(type == 2) {
			int l, r;
			cin>>l>>r;
			cout<<query(segtree, 0, n-1, 1, l, r-1)<<endl;
		} else {
			int i, v;
			cin>>i>>v;
			update(arr, segtree, 0, n-1, 1, i, v);
		}
	}
	return 0;
}
