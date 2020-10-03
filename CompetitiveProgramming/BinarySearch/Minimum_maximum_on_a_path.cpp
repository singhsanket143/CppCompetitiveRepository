// Problem Link - https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/D
/* By Sanket Singh */
#include<bits/stdc++.h>
#define ll 				long long int
#define mod             1000000007
#define inf             1e18
#define pb 				push_back
#define pii 			pair<int, int >
#define piv				pair<int, vector<int> >
#define mp				make_pair
#define REP(i,n) 		for(int i=0;i<(n);i++)
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

class Graph {
public:
	int v, e;
	list<pii >* adj;
	vector<int> parent;
	vector<int> dist;
	int result;
	Graph(int v, int e) {
		this->v = v;
		this->e = e;
		this->adj = new list<pii >[this->v];
	}

	void addEdge(int src, int dest, int wt, int bidir = false) {
		this->adj[src].pb(mp(dest, wt));
		if(bidir) {
			this->adj[dest].pb(mp(dest, wt));
		}
	} 

	piv bfsPathFinderInKStep(int src, int dest, int k, ll mid) {
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
				if(!visited[el.first]) {
					if(el.second <= mid) {
						visited[el.first] = true;
						qu.push(el.first);
						dist[el.first] = dist[curr] + 1;
						parent[el.first] = curr;
					}
				}	
			}
		}
		return mp(dist[dest], parent);
	}
};

int main(int argc, char const *argv[]) {
	file_i_o();
	ll n, m, d, src, dest, wt;
	ll min_wt = numeric_limits<ll>::max(), max_wt = numeric_limits<ll>::min();
	cin>>n>>m>>d;
	Graph *g = new Graph(n, m);
	for(int i = 0; i < m; i++) {
		cin>>src>>dest>>wt;
		min_wt = min(min_wt, wt);
		max_wt = max(max_wt, wt);
		g->addEdge(src-1, dest-1, wt);
	}
	ll lo = min_wt, hi = max_wt;
	ll ans = -1;
	vector<int> parent;
	while(lo <= hi) {
		ll mid = lo + (hi - lo) / 2;
		piv result = g->bfsPathFinderInKStep(0, n-1, d, mid);
		if(result.first == -1 or result.first > d) {
			lo = mid + 1;
		} else {
			ans = result.first;
			parent = result.second;
			hi = mid - 1;
		}
	}
	cout<<ans<<endl;
	if(ans == -1) return 0; 
	int vertex = n-1;
	vector<int> path;
	while(parent[vertex] != vertex) {
		path.pb(vertex+1);
		vertex = parent[vertex];
	}
	path.pb(vertex+1);
	reverse(path.begin(), path.end());
	REP(i,path.size()) {
		cout<<path[i]<<" ";
	}
	return 0;
}