// Problem Link - 
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
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define piv				pair<ll, vector<int> >
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
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

class Graph {
public:
	int v, e; // no of vertices and no of edges
	list<pii >* adj; // adjacency list
	Graph(int v, int e) { // constructor
		this->v = v;
		this->e = e;
		this->adj = new list<pii >[this->v];
	}
	
	void addEdge(int src, int dest, int wt = 0, bool bidir = false) {
		this->adj[src].pb(mp(dest, wt));
		if(bidir) {
			this->adj[dest].pb(mp(src, wt));
		}
	}

	piv bfsPathFinderWithKedges(int src, int dest, int k, ll mid) { // ?????
		queue<int> qu;
		qu.push(src);
		vector<bool> visited(this->v, false);
		vector<int> parent(this->v, -1);
		vector<int> dist(this->v, -1);

		dist[src] = 0;
		parent[src] = src;
		while(!qu.empty()) {
			int curr = qu.front();
			qu.pop();
			for(pii el: this->adj[curr]) {
				if(not visited[el.ff]) {
					if(el.ss <= mid) {
						visited[el.ff] = true;
						qu.push(el.ff);
						dist[el.ff] = dist[curr] + 1;
						parent[el.ff] = curr;
					}
				}
			}
		}
		return mp(dist[dest], parent);
	}

};

int main(int argc, char const *argv[]) {
	file_i_o();
	ll n, m, d;
	ll src, dest, wt;
	ll min_wt = numeric_limits<ll>::max(), max_wt = numeric_limits<ll>::min();
	cin>>n>>m>>d;
	Graph *g = new Graph(n, m);
	loop(i, 0, m-1) {
		cin>>src>>dest>>wt;
		min_wt = min(min_wt, wt);
		max_wt = max(max_wt, wt);
		g->addEdge(src-1, dest-1, wt);
	}
	ll lo = min_wt, hi = max_wt;
	ll ans = -1;
	vector<int> parent;
	while(lo <= hi) {
		ll mid = lo + (hi - lo)/2;
		piv result = g->bfsPathFinderWithKedges(0, n-1, d, mid);
		if(result.ff == -1 or result.ff > d) {
			lo = mid + 1;
		} else {
			ans = result.ff;
			parent = result.ss;
			hi = mid - 1;
		}
	}
	cout<<ans<<endl;
	if(ans == -1) return 0;
	int v = n-1;
	vector<int> path;
	while(parent[v] != v) {
		path.pb(v+1);
		v = parent[v];
	}
	path.pb(v+1);
	reverse(path.begin(), path.end());
	logarr(path, 0, path.size() - 1);
	return 0;
}
