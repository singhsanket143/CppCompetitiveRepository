#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <string>
using namespace std;

template<typename T>
class Graph {
	map<T, list<T> > adj;
public:
	Graph() {}
	void addEdge(T u, T v, bool bidir = true) {
		adj[u].push_back(v);
		if(bidir) {
			adj[v].push_back(u);
		}
	}
	void printAdjList() {
		for(auto row: adj) {
			cout<<row.first<<"->";

			for(T element: row.second) {
				cout<<element<<", ";
			}
			cout<<endl;	
		}
	}
	void TopologicalSort() {
		queue<T> q;
		std::map<T, bool> visited;
		std::map<T, int> indegree;

		for(auto i:adj) {
			T node = i.first;
			visited[node] = false;
			indegree[node] = 0;
		}

		// Init the indegrees
		for(auto i: adj) {
			T u = i.first;
			for(auto v: adj[u]) {
				indegree[v]++;
			}
		}

		for(auto i: adj) {
			T node = i.first;
			if(indegree[node] == 0) {
				q.push(node);
			}
		}

		while(!q.empty()) {
			T node = q.front();
			q.pop();
			cout<<node<<"-->";
			for(T neighbour: adj[node]) {
				indegree[neighbour]--;
				if(indegree[neighbour] == 0) {
					q.push(neighbour);
				}
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	Graph<string> g;
	g.addEdge("0", "1");
	g.addEdge("1", "3");
	g.addEdge("3", "0");
	g.addEdge("3", "2");
	g.addEdge("2", "0");
	g.printAdjList();
	return 0;
}
