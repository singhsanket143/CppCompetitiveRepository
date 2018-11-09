#include <iostream>
#include <list>
#include <queue>
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
};

int main(int argc, char const *argv[])
{
	int board[50] = {0};

	Graph g(50);
	board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;
	
	for(int u = 0; u < 36; u++) {
		for(int dice = 1; dice <= 6; dice++) {
			int v = u + dice + board[u+dice];
			g.addEdge(u, v, false);
		}
	}
	g.bfs(0, 36);
	return 0;
}
