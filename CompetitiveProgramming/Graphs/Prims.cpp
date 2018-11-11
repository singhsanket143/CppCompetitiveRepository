#include <iostream>
#include <list>
#include <queue>
#include <map>
#define inf 1e9
using namespace std;

class Graph {
	int v;
	list<pair<int, int> > *adj;

public:
	Graph(int v) {
		this->v = v;
		adj = new list<pair<int, int> >[v];
	}

	void addEdge(int u, int v, int w, bool bidir = true) {
		adj[u].push_back(make_pair(v, w));
		if(bidir) {
			adj[v].push_back(make_pair(u, w));
		}
	}

	int findminVertex(int *weight, bool *visited, int v) {
		int minVertex = -1;
		for(int i=0;i<v;i++) {
			if(!visited[i] and (minVertex == -1 or weight[i] < weight[minVertex])) {
				minVertex = i;
			}
		}
		return minVertex;
	}

	void prims() {
		int *parent = new int[v];
		int *weight = new int[v];
		bool *visited = new bool[v];
		for(int i=0;i<v;i++) {
			visited[i] = false;
			weight[i] = inf;
		}
		parent[0] = -1;
		weight[0] = 0;

		for(int i=0;i<v;i++) {
			int minVertex = findminVertex(weight, visited, v);
			visited[minVertex] = true;
			for(auto neighbour:adj[minVertex]) {
				if(!visited[neighbour.first]) {
					if(weight[neighbour.first] > neighbour.second) {
						weight[neighbour.first] = neighbour.second;
						parent[neighbour.first] = minVertex;
					}
				}
			}
		}

		// for(int i=1;i<v;i++) {
		// 	cout<<i<<"--"<<parent[i]<<" with weight "<<weight[i]<<endl;
		// }
		int totalWeight = 0;
		for(int i=1;i<v;i++) {
			totalWeight+=weight[i];
		}
		cout<<totalWeight<<endl;
	}
};

int main(int argc, char const *argv[])
{
	int n, e;
	cin>>n>>e;
	Graph g(n);
	for(int i=0;i<e;i++) {
		int u, v, w;
		cin>>u>>v>>w;
		g.addEdge(u, v, w);	
	}
	g.prims();
	return 0;
}
