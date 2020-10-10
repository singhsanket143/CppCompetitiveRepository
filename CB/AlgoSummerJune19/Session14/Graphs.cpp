#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graphs {
public:
	int v;
	list<int> *arr;

	Graphs(int v) {
		this->v = v;
		arr = new list<int>[this->v];
	}

	void addEdge(int u, int v, bool bidir = true) {
		this->arr[u].push_back(v);
		if(bidir == true) {
			this->arr[v].push_back(u);
		}
	}

	void display() {
		for(int i=0;i<this->v;i++) {
			cout<<i<<"--";
			for(int el:this->arr[i]) {
				cout<<el<<",";
			}
			cout<<endl;
		}
	}

	void bfs(int src) {
		queue<int> qu;
		bool *visited = new bool[this->v]();
		qu.push(src);
		visited[src] = true;
		while(!qu.empty()) {
			int to_be_removed = qu.front();
			qu.pop();
			cout<<to_be_removed<<" ";
			for(int neighbours: this->arr[to_be_removed]) {
				if(visited[neighbours]==false) {
					qu.push(neighbours);
					visited[neighbours] = true;
				}
			}
		}
	}

	void dfsHelper(int src, bool* visited) {
		visited[src] = true;
		cout<<src<<" ";
		for(int neighbours: this->arr[src]) {
			if(visited[neighbours] == false) {
				dfsHelper(neighbours, visited);
			}
		}
	}

	void dfs(int src) {
		bool *visited = new bool[this->v];
		dfsHelper(src, visited);
	}

	void dfsHelper1(int src, bool* visited) {
		visited[src] = true;
		for(int neighbours: this->arr[src]) {
			if(visited[neighbours] == false) {
				dfsHelper1(neighbours, visited);
			}
		}
	}

	int connectedComponent() {
		int result = 0;
		bool *visited = new bool[this->v];
		for(int i=0;i<this->v;i++) {
			if(visited[i]==false) {
				dfsHelper1(i, visited);
				result++;
			}
		}
		return result;
	}
};

int main(int argc, char const *argv[])
{
	Graphs *g = new Graphs(7);
	g->addEdge(0, 1);
	g->addEdge(0, 2);
	g->addEdge(3, 1);
	g->addEdge(3, 2);
	// g->addEdge(4, 1);
	g->addEdge(4, 5);
	g->addEdge(4, 6);
	g->addEdge(5, 6);
	// g->display();
	// g->dfs(0);
	cout<<g->connectedComponent();
	return 0;
}
