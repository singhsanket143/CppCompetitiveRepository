#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

class Graph {
public:
	int v; // Number of vertices
	list<int> *adj; // Array of linked list
	Graph(int v) {
		// Constructor
		this->v = v;
		adj = new list<int>[v]; // Initialise the array of list
	}

	void addEdge(int a, int b, bool bidir=true) {
		adj[a].push_back(b);
		if(bidir) { // If the graph is not directional
			adj[b].push_back(a);
		}
	}

	void printAdj() {
		for(int i=0;i<v;i++) {
			cout<<i<<" == ";
			for(int el:adj[i]) {
				cout<<el<<"-->";
			}
			cout<<"END\n";
		}
	}

	void bfs(int src) {
		bool *visited = new bool[this->v]();
		queue<int> qu;
		qu.push(src);
		visited[src] = true;
		while(!qu.empty()) {
			int node = qu.front();
			cout<<node<<", ";
			qu.pop();
			for(int el:this->adj[node]) {
				if(visited[el] == false) {
					qu.push(el);
					visited[el] = true;
				}
			}
		}
	}

	void sssp_bfs(int src, int dest) { // Single source shortest path using bfs
		bool *visited = new bool[this->v]();
		int *dist = new int[this->v]();
		int *parent = new int[this->v];
		for(int i=0;i<this->v;i++) {
			parent[i] = -1;
		}
		queue<int> qu;
		qu.push(src);
		visited[src] = true;
		while(!qu.empty()) {
			int node = qu.front();
			// cout<<node<<", ";
			qu.pop();
			for(int neighbour:this->adj[node]) {
				if(visited[neighbour] == false) {
					qu.push(neighbour);
					visited[neighbour] = true;
					parent[neighbour] = node;
					dist[neighbour] = dist[node] + 1;
				}
			}
		}
		int temp = dest;
		while(temp!=-1) {
			cout<<temp<<"<--";
			temp=parent[temp];
		}
	}

	void dfsHelper(int node,unordered_map<int, bool> &visited) {
		visited[node] = true;
		cout<<node<<", ";
		for(int el: this->adj[node]) {
			if(visited.find(el)==visited.end()) {
				dfsHelper(el, visited);
			}
		}
	}

	void dfs(int src) {
		unordered_map<int, bool> visited;
		dfsHelper(src, visited);
	}

	void dfsHelperCC(int node,unordered_map<int, bool> &visited) {
		visited[node] = true;
		// cout<<node<<", ";
		for(int el: this->adj[node]) {
			if(visited.find(el)==visited.end()) {
				dfsHelperCC(el, visited);
			}
		}
	}

	int connectedComponent() {
		int result = 0;
		unordered_map<int, bool> visited;
		for(int i=0;i<this->v;i++) {
			if(visited.find(i) == visited.end()) {
				dfsHelperCC(i, visited);
				result++;
			}
		}
		return result;
	}

	void dfsHelperTS(int node,unordered_map<int, bool> &visited, list<int> &ordering) {
		visited[node] = true;
		// cout<<node<<", ";
		for(int el: this->adj[node]) {
			if(visited.find(el)==visited.end()) {
				dfsHelperTS(el, visited, ordering);
			}
		}
		ordering.push_front(node);

		
	}

	void topologicalDFS() {
		unordered_map<int, bool> visited;
		list<int> ordering;
		for(int i=0;i<this->v;i++) {
			if(visited.find(i)==visited.end()) {
				dfsHelperTS(i, visited, ordering);
			}
		}
		for(int el: ordering) {
			cout<<el<<"<-";
		}
	}

	void topologicalBFS() {
		int *indegree = new int[this->v](); // Initialise indegree array
		bool *visited = new bool[this->v]();
		for(int i=0;i<v;i++) {
			for(int el:adj[i]) {
				indegree[el]++; // Fill up indegree array
			}
		}
		queue<int> qu;
		for(int i=0;i<this->v;i++) {
			if(indegree[i] == 0) {
				qu.push(i);
			}
		}
				while(!qu.empty()) {
					int node = qu.front();
					cout<<node<<" ";
					qu.pop();
					for(int neighbour: this->adj[node]) {
						if(visited[neighbour] == false) {
							indegree[neighbour]--;
							if(indegree[neighbour]==0) {
								qu.push(neighbour);
								visited[neighbour] = true;
							}
						}
					}
				}
	}
};


int main(int argc, char const *argv[])
{
	/* code */
	Graph g(6);

	g.addEdge(0, 1, false);
	g.addEdge(2, 0, false);
	g.addEdge(1, 3, false);
	g.addEdge(2, 3, false);
	g.addEdge(3, 4, false);
	g.addEdge(5, 2, false);
	// // g.addEdge(2, 4);
	// g.addEdge(4, 5);
	// g.addEdge(4, 6);
	// g.addEdge(5, 6);

	g.printAdj();
	// cout<<" ===================="<<endl;
	// g.bfs(0);
	// cout<<" ===================="<<endl;
	// g.sssp_bfs(0, 6);
	// cout<<" ===================="<<endl;
	// g.dfs(0);
	// cout<<g.connectedComponent();
	g.topologicalBFS();
	return 0;
}
