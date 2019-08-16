#include <iostream>
#include <map>
#include <list>
#include <string>
#include <queue>
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
	bool isCyclicBFS(T src){
		std::map<T, bool> visited;
		std::map<T, T> parent;
		std::queue<T> q;
		q.push(src);
		visited[src] = true;
		parent[src] = src;
		while(!q.empty()) {
			T node = q.front();
			q.pop();
			for(T neighbour: adj[node]) {
				if(visited[neighbour] == true and parent[neighbour] != node) {
					return true;
				} else {
					visited[neighbour] = true;
					parent[neighbour] = node;
					q.push(neighbour);
				}
			}
		}
		return false;
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
