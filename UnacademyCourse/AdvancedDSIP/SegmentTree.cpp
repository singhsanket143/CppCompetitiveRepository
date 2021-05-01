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

/*
tidx will be used to operate on segtree
s and e will be used to denote the range of segment in each recursive call
*/
//O(n)
void build(vi &arr, vi &seg, int s, int e, int tidx) {
	if(s == e) {
		seg[tidx] = arr[s];
		return;
	}
	int m = mid(s, e);
	build(arr, seg, s, m, 2*tidx);
	build(arr, seg, m+1, e, 2*tidx+1);
	// self work
	seg[tidx] = seg[2*tidx] + seg[2*tidx+1];
}

/*
i is the index of update in arr
v is the value with which we need to update
*/
//O(logn)
void update(vi &arr, vi &seg, int s, int e, int tidx, int i, int v){
	if(s == e) {
		arr[i] = v;
		seg[tidx] = v;
		return;
	}
	int m = mid(s, e);
	if(i > m) {
		update(arr, seg, m+1, e, 2*tidx+1, i, v); // rst
	} else {
		update(arr, seg, s, m, 2*tidx, i, v);// lst
	}
	seg[tidx] = seg[2*tidx] + seg[2*tidx+1];
}

//O(logn)
ll query(vi &seg, int s, int e, int tidx, int left, int right) {
	if(s > right or e < left) {
		// complete outside
		return 0;
	}
	if(s >= left and e <= right) {
		// complete inside
		return seg[tidx];
	}
	// partial overlap
	int m = mid(s, e);
	ll a1 = query(seg, s, m, 2*tidx, left, right);
	ll a2 = query(seg, m+1, e, 2*tidx+1, left, right);
	return a1+a2;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int n;
	cin>>n;
	vi arr(n);
	loop(i, 0, n-1) cin>>arr[i];

	vi segtree(4*n, 0);

	build(arr, segtree, 0, n-1, 1);
	int q;
	cin>>q;
	while(q--) {
		int type;
		cin>>type;
		int x, y;
		cin>>x>>y;
		if(type == 1) {
			update(arr, segtree, 0, n-1, 1, x, y);
		} else {
			cout<<query(segtree, 0, n-1, 1, x, y)<<endl;
		}	
	}

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
