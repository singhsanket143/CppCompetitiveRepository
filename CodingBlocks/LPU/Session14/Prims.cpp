#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Graph {
public:
	int v; 
	list<pair<int, int> > *adj;
	Graph(int v) {
		this->v = v;
		adj = new list<pair<int, int> >[v]; 
	}

	void addEdge(int a, int b, int w, bool bidir=true) {
		adj[a].push_back(make_pair(w, b));
		if(bidir) { 
			adj[b].push_back(make_pair(w, a));
		}
	}

	void printAdj() {
		for(int i=0;i<v;i++) {
			cout<<i<<" == ";
			for(auto el:adj[i]) {
				cout<<el.second<<"("<<el.first<<")"<<"-->";
			}
			cout<<"END\n";
		}
	}

	int Prims() {
		int totalWeight = 0;
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
		pq.push(make_pair(0, 0));
		unordered_map<int, bool> visited;
		// Setup complete

		while(!pq.empty()) {
			int curr_vertex = pq.top().second;
			if(visited.find(curr_vertex)!=visited.end()) {
				pq.pop();
				continue;
			}
			visited[curr_vertex] = true;
			totalWeight+=pq.top().first;
			pq.pop();
			for(auto neighbour: adj[curr_vertex]) {
				pq.push(make_pair(neighbour.first, neighbour.second));
			}
		}
		return totalWeight;
	}
};


int main(int argc, char const *argv[])
{
	/* code */
	Graph g(7);

	g.addEdge(0, 2, 2);
	g.addEdge(2, 3, 2);
	g.addEdge(0, 1, 2);
	g.addEdge(1, 3, 1);
	g.addEdge(2, 4, 1);
	g.addEdge(4, 5, 2);
	g.addEdge(5, 6, 6);
	g.addEdge(4, 6, 4);
	g.printAdj();
	cout<<g.Prims();

	return 0;
}
