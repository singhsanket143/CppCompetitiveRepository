#include <iostream>
#include <list>
#include <queue>
#include <map>
using namespace std;

class Graph {
	int v;
	list<int> *adj;

public:
	Graph(int v) {
		this->v = v;
		adj = new list<int>[v];
	}

	void addEdge(int u, int v, bool bidir = true) {
		adj[u].push_back(v);
		if(bidir) {
			adj[v].push_back(u);
		}
	}

	void printAdjList() {
		for(int i=0;i<this->v;i++) {
			cout<<i<<"->";
			for(int node:adj[i]) {
				cout<<node<<", ";
			}
			cout<<endl;
		}
	}

	void bfs(int src) {
		queue<int> q;
		bool *visited = new bool[this->v+1]{0};

		q.push(src);
		visited[src] = true;

		while(!q.empty()) {
			int node = q.front();
			cout<<node<<" ";
			q.pop();
			for(int neighbour: adj[node]) {
				if(!visited[neighbour]) {
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}

		delete [] visited;
	}


	void bfs(int src,int dest){
     	//Traverse all the nodes of the graph
     	queue<int> q;
     	bool *visited = new bool[v+1]{0};
     	int *dist = new int[v+1]{0};
     	int *parent = new int[v+1];

     	for(int i=0;i<v;i++){
     		parent[i] = -1;
     	}

     	q.push(src);
     	visited[src] = true;



     	while(!q.empty()){
     		int node = q.front();
     		cout<<node<<" ";
     		q.pop();

     		for(int neighbour:adj[node]){
     			
     			if(!visited[neighbour]){
     				q.push(neighbour);
     				visited[neighbour] = true;
     				dist[neighbour] = dist[node]  + 1;
     				parent[neighbour] = node;
     			}
     		}
     	}
     	cout<<endl;
     	//Print the distances of every node from source
     	for(int i=0;i<v;i++){
     		//cout<<i<<"node having dist "<<dist[i]<<endl;
     	}

     	cout<<"Shortest dist is "<<dist[dest]<<endl;
     	cout<<"Shortest path is ";

     	int temp = dest;
     	while(temp!=-1){
     		cout<<temp<<"<--";
     		temp = parent[temp];
     	}
     }

     void dfsHelper(int src, map<int, bool> &visited) {
     	visited[src] = true;
     	cout<<src<<" ";
     	for(int neighbour : adj[src]) {
     		if(!visited[neighbour]) {
     			dfsHelper(neighbour, visited);
     		}
     	}
     }

     

     void dfs(int src) {
     	map<int, bool> visited;
     	dfsHelper(src, visited);
     }

     void dfsHelper2(int src, map<int, bool> &visited) {
     	visited[src] = true;
     	// cout<<src<<" ";
     	for(int neighbour : adj[src]) {
     		if(not visited[neighbour]) {
     			dfsHelper2(neighbour, visited);
     		}
     	}
     }

     int connectedComponents() {
     	map<int, bool> visited;
     	int component = 0;
     	for(int i=0;i<v;i++) {
     		int city = i;
     		if(!visited[i]) {
     			dfsHelper2(i, visited);
     			component++;
     		}
     	}
     	return component;
     }
};

int main(int argc, char const *argv[])
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(1, 3);
	g.addEdge(1, 2);
	g.addEdge(0, 2);
	
	// g.printAdjList();
	g.dfs(0);
     // g.bfs(0);
	return 0;
}
