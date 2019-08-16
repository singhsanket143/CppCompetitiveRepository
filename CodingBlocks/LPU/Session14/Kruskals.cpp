#include <iostream>
#include <algorithm>
// #include <vector>
using namespace std;

class Edge {
public:
	int src, dest, wt;
};

class Set {
public:
	int parent, rank;
};

int find(int i, Set *set) {
	if(set[i].parent != i) {
		set[i].parent = find(set[i].parent, set);
	}

	return set[i].parent;
}

int find1(int i, Set *set) {
	if(set[i].parent != i) {
		return find1(set[i].parent, set);
	}

	return set[i].parent;
}

void Union(Set *set, int u, int v) {
	int v_root = find(v, set);
	int u_root = find(u, set);

	if (set[v_root].rank <= set[u_root].rank) {
		set[v_root].parent = u_root;
		set[u_root].rank++;
	} else if (set[v_root].rank > set[u_root].rank) {
		set[u_root].parent = v_root;
		set[v_root].rank++;
	} 
}

bool cmp(Edge e1, Edge e2) {
	return e1.wt < e2.wt;
}

int kruskals(Edge *edges, int e, int n) { // n = no of vertices, e = no of edges
	sort(edges, edges+e, cmp);
	// vector<Edge> result;
	Set *set = new Set[n];
	for(int i=0;i<n;i++) {
		set[i].parent = i;
		set[i].rank = -1;
	}
	int totalWeight = 0;
	for(int i=0;i<e;i++) {
		Edge currentEdge = edges[i];
		int srcParent = find(currentEdge.src, set);
		int destParent = find(currentEdge.dest, set);
		if(srcParent != destParent) {
			Union(set, srcParent, destParent);
			totalWeight+=currentEdge.wt;
		}
	}
	return totalWeight;
}

int main(int argc, char const *argv[])
{
	int n, e;
	cin>>n>>e;
	Edge *edge = new Edge[e];
	for(int i=0;i<e;i++) {
		int s, d, w;
		cin>>s>>d>>w;
		edge[i].src = s;
		edge[i].wt = w;
		edge[i].dest = d;
	}
	cout<<kruskals(edge, e, n);
	return 0;
}
