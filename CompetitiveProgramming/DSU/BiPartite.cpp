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

pii Get(vi &parent, vi &len, ll a) {
	if(parent[a] == a) {
		return {a, 0};
	}
	pii val = Get(parent,len, parent[a]);
	parent[a] = val.ff;
	len[a] = (len[a]+val.ss)%2;
	return {parent[a], len[a]};

}

void Union(vi &parent, vi &size, vi &len, ll a, ll b) {
	pii vala = Get(parent, len, a);
	pii valb = Get(parent, len, b);
	if (size[vala.ff] > size[valb.ff]) {
    	swap(vala, valb);
	}
	// log(vala.ff, valb.ff);
	// logarr(parent, 0, parent.size() - 1);
	parent[vala.ff] = valb.ff;
	len[vala.ff] = (1 + vala.ss + valb.ss) % 2;
	size[valb.ff] += size[vala.ff];
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int n, m;
	cin>>n>>m;
	vi parent(n);
	vi size(500000, 1);
	vi len(500000, 0);
	loop(i, 0, n-1) {
		parent[i] = i;
	}
	int shift = 0;
	while(m--) {
		int t, x, y;
		cin>>t>>x>>y;
		x = (x+shift)%n;
		y = (y+shift)%n;
		// log(t, x, y);
		if(t == 0) {
			Union(parent, size, len, x, y);
		} else {
			pii valx = Get(parent, len, x);
			pii valy = Get(parent, len, y);
			if(valx.ss == valy.ss) {
				cout<<"YES\n";
				shift = (shift+1)%n;
			} else {
				cout<<"NO\n";
			}
		}
	}

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
