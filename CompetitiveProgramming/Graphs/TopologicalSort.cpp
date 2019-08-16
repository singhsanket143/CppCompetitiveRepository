#include <iostream>
#include <map>
#include <list>
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

	void dfsHelper(T node, map<T, bool> &visited, list<int> &ordering) {
		visited[node] = true;
		for(T neighbour: adj[node]) {
			if(!visited[neighbour])
				dfsHelper(neighbour, visited, ordering);
		}
		ordering.push_front(node);
	}

	void topologicalSort() {
		std::map<T, bool> visited;
		list<T> ordering;
		for(auto i: adj) {
			T node = i.first;
			if(!visited[node]) {
				dfsHelper(node, visited, ordering);
			}
		}
		for(T element: ordering) {
			cout<<element<<"-->";
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
