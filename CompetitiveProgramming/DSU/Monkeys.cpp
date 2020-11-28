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

class Graph {
public:
	int v;
	pii *adj;
	set<ll> *adjlist;
	Graph(int v) {
		this->v = v;
		adj = new pii[v];
		adjlist = new set<ll>[v];
	}
	void addEdge(ll x, ll l, ll r) {
		adj[x] = {l, r};
		if(l != -1) {
			adjlist[l].insert(x);
			adjlist[x].insert(l);
		}
		if(r != -1) {
			adjlist[r].insert(x);
			adjlist[x].insert(r);
		}
	}

	void addHand(ll x, ll h, ll v) {
		if(h == 1) {
			adj[x].ff = v;
			adjlist[v].insert(x);
			adjlist[x].insert(v);

		}
		else {
			adj[x].ss = v;
			adjlist[v].insert(x);
			adjlist[x].insert(v);
		}

	}

	ll Get(vi &parent, ll a) {
		return parent[a] = (parent[a] == a ? a : Get(parent, parent[a]));
	}

	void dfsHelper(ll src, ump<int, bool> &visited, ll val, vi &ans, vi &parent) {
     	visited[src] = true;
     	// cout<<src<<endl;
     	if(ans[src] == -2 and Get(parent, src) == 1)
     		ans[src] = val;
     	// if(adj[src].ff!=-1) {
     	// 	if(!visited[adj[src].ff]) {
     	// 		dfsHelper(adj[src].ff, visited, val, ans, parent);
     	// 	}
     	// }
     	// if(adj[src].ss!=-1) {
     	// 	if(!visited[adj[src].ss]) {
     	// 		dfsHelper(adj[src].ss, visited, val, ans, parent);
     	// 	}
     	// }

     	for(auto i : adjlist[src]) {
     		if(ans[i] == -2 and !visited[i]) {
     			dfsHelper(i, visited, val, ans, parent);
     		}
     	}
     }

	void dfs(ll root, ll val, vi &ans, vi &parent) {
		ump<int, bool> visited;
     	dfsHelper(root, visited, val, ans, parent);
     	adjlist[root].clear();
	}

	void removeEdge(ll x, ll h) {
		if(h == 1) {
			adjlist[x].erase(adj[x].ff);
			adj[x].ff = -1;
		}
		else {
			adjlist[x].erase(adj[x].ss);
			adj[x].ss = -1;
		}
	}

	void print() {
		for(int i = 1; i < v; i++) {
			cout<<adj[i].ff<<" "<<adj[i].ss<<endl;
		}
	}
};

ll Get(vi &parent, ll a) {
	return parent[a] = (parent[a] == a ? a : Get(parent, parent[a]));
}

void Union(vi &parent, vi &rank, ll a, ll b) {
	a = Get(parent, a);
	b = Get(parent, b);
	if(a == b) return;
	if(a == 1) {
		parent[b] = a;
		return;
	} 
	if(b == 1) {
		parent[a] = b;
		return;
	}
	if(rank[a] == rank[b]) {
		rank[a]++;
	}
	if(rank[a] > rank[b]) {
		parent[b] = a;
	} else {
		parent[a] = b;
	}
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	ll n, m;
	cin>>n>>m;
	vi parent(n+1);
	vi rank(n+1, 0);
	loop(i, 0, n) {
		parent[i] = i;
	}
	Graph g(n+1);

	vector<pair<int, int> > monkey(n+1);
	loop(i, 1, n) {
		int l, r;
		cin>>l>>r;
		monkey[i].ff = l;
		monkey[i].ss = r;
		g.addEdge(i, l, r);
	}
	vector<pair<int, int> > query(m);
	loop(i, 0, m-1) {
		int m, h;
		cin>>m>>h;
		query[i].ff = m;
		query[i].ss = h;
		g.removeEdge(m, h);
	}
	// g.print();
	for(int i=1;i<=n;i++) {
		if(g.adj[i].ff != -1) {
			Union(parent, rank, i, g.adj[i].ff);
		}
		if(g.adj[i].ss != -1) {
			Union(parent, rank, i, g.adj[i].ss);
		}
	}
	vector<ll> ans(n+1, -2);
	for(int i=1;i<=n;i++) {
		int x = Get(parent, i);
		if(x == 1) ans[i] = -1;
	}
	for(int i = m-1; i >= 0; i--) {
		int m1 = query[i].ff;
		int h = query[i].ss;
		int m2 = (h == 1) ? monkey[m1].ff : monkey[m1].ss;
		if(m1 == m2) continue;
		if(Get(parent, m1) == 1 and Get(parent, m2) == 1) continue;
 		Union(parent, rank, m1, m2);
		int x = Get(parent, m1);
		g.addHand(m1, h, m2);
		// log(m1, m2, h, x);
		if(x == 1) {
			g.dfs(m1, i, ans, parent);
			// loop(j, 1, n) {
			// 	if(ans[j] == -2 and Get(parent, j) == 1) ans[j] = i;
			// }
		}
	}
	ans[1] = -1;
	for(int i = 1; i <= n; i++) {
		cout<<ans[i]<<endl;
	}
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
