#include <iostream>
#include <list>
#include <queue>
#include <map>
using namespace std;

class Graphs {
public:
	int v;
	list<pair<int, int> > *arr;

	Graphs(int v) {
		this->v = v;
		arr = new list<pair<int, int> >[this->v];
	}

	void addEdge(int u, int v, int w, bool bidir = true) {
		this->arr[u].push_back(make_pair(w, v));
		if(bidir == true) {
			this->arr[v].push_back(make_pair(w, u));
		}
	}

	int prims() {
		priority_queue <pair<int, int>, vector <pair<int, int> >, greater<pair<int, int> > > pq;
		pq.push(make_pair(0, 0));
		for(int i=1;i<this->v;i++) {
			pq.push(make_pair(INT_MAX, i));
		} 
		int total_vertex = 0;
		int result = 0;
		bool *visited = new bool[this->v]();
		while(total_vertex < this->v) {
			int curr_vertex = pq.top().second;
			if(visited[curr_vertex] == true) {
				pq.pop();
				continue;
			}
			visited[curr_vertex] = true;
			total_vertex++;
			result += pq.top().first;
			pq.pop();
			for(pair<int, int> p: this->arr[curr_vertex]) {
				if(visited[p.second] == false) {
					pq.push(make_pair(p.first, p.second));
				}
			}
		}
		return result;
	}
};

int main(int argc, char const *argv[])
{
	Graphs *g = new Graphs(7);
	// g->addEdge(0, 1);
	// g->addEdge(0, 2);
	// g->addEdge(3, 1);
	// g->addEdge(3, 2);
	// // g->addEdge(4, 1);
	// g->addEdge(4, 5);
	// g->addEdge(4, 6);
	// g->addEdge(5, 6);
	// g->display();
	// g->dfs(0);
	// cout<<g->connectedComponent();
	return 0;
}
