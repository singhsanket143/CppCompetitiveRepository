// adjacency map
#include "iostream"
#include "map"
#include "list"
#include "string"

using namespace std;

// templates
template<typename T>
class Graph {
public:
	map<T, list<T> > adj;
	Graph() {
	}

	void addEdge(T u, T v, bool bidir = true) {
		adj[u].push_back(v);
		if(bidir) {
			adj[v].push_back(u);
		}
	}

	void display() {
		for(auto row: adj) {
			cout<<row.first<<"->";
			for(T el: row.second) {
				cout<<el<<"->";
			}
			cout<<endl;
		}
	}

};


int main(int argc, char const *argv[])
{
	/* code */
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	Graph<string> g;
	g.addEdge("delhi", "mumbai");
	g.addEdge("delhi", "blr");
	g.addEdge("blr", "chennai");
	g.addEdge("chennai", "punjab");
	g.display();
	return 0;
}