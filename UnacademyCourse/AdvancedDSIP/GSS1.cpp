// Problem Link - https://www.spoj.com/problems/GSS1/
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

class node {
public:
	ll sum;
	ll bps; // best prefix sum
	ll bss; // best suffix sum
	ll maxSum;
};

void build(vi &arr, vector<node*> &tree, ll s, ll e, ll ti) {
	if(s == e) {
		tree[ti]->maxSum = arr[s];
		tree[ti]->bss = arr[s];
		tree[ti]->bps = arr[s];
		tree[ti]->sum = arr[s];
		return;
	}
	ll m = mid(s, e);
	build(arr, tree, s, m, 2*ti);
	build(arr, tree, m+1, e, 2*ti+1);
	tree[ti]->sum = tree[2*ti]->sum + tree[2*ti+1]->sum;
	tree[ti]->bps = max(tree[2*ti]->bps, tree[2*ti]->sum+tree[2*ti+1]->bps);
	tree[ti]->bss = max(tree[2*ti+1]->bss, tree[2*ti+1]->sum+tree[2*ti]->bss);
	tree[ti]->maxSum = max(max(tree[2*ti]->maxSum, tree[2*ti+1]->maxSum), tree[2*ti]->bss+tree[2*ti+1]->bps);
}

node* query(vector<node*> &tree, ll s, ll e, ll ti, ll l, ll r) {
	node *temp = new node();
	temp->sum = temp->bss = temp->bps = temp->maxSum = INT_MIN;
	if(r < s or l > e) return temp;
	if(s >= l and e <= r) return tree[ti];
	ll m = mid(s, e);
	node *left = query(tree, s, m, 2*ti, l, r);
	node *right = query(tree, m+1, e, 2*ti+1, l, r);
	temp->sum = left->sum + right->sum;
	temp->bps = max(left->bps, left->sum+right->bps);
	temp->bss = max(right->bss, right->sum+left->bss);
	temp->maxSum = max(max(left->maxSum, right->maxSum), left->bss+right->bps);
	return temp;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int n;
	cin>>n;
	vi arr(n);
	loop(i, 0, n-1) cin>>arr[i];
	vector<node*> tree(4*n);
	loop(i, 0, 4*n-1) tree[i] = new node();
	build(arr, tree, 0, n-1, 1);
	int q;
	cin>>q;
	while(q--) {
		int l, r;
		cin>>l>>r;
		l--;
		r--;
		node *res = query(tree, 0, n-1, 1, l, r);
		cout<<res->maxSum<<endl;
	}


	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
