#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

// T denotes any general type -> later we will replace T with int/float/string etc
template<typename T>
class Graph {
public:
	unordered_map<T, unordered_map<T, int> > adj;
	Graph() {} // constructor
	void addEdge(T u, T v, int wt, bool bidir = true) {
		adj[u][v] = wt; // you have added an edge from u - v with weight wt
		if(bidir) {
			adj[v][u] = wt;
		}
	}

	void printAdj() {
		for(auto row : adj) {
			cout<<row.first<<" := ";
			for(auto neighbour : row.second) {
				cout<<"("<<neighbour.first<<","<<neighbour.second<<") -> ";
			}
			cout<<endl;
		}
	}
};

int main(int argc, char const *argv[])
{
	Graph<string> g;
	g.addEdge("Delhi", "Mumbai", 350, false);
	g.addEdge("Delhi", "Bengaluru", 50, false);
	g.addEdge("Kolkata", "Mumbai", 30, false);
	g.addEdge("Chandigarh", "Goa", 35, false);
	g.addEdge("Delhi", "Goa", 765, false);
	g.addEdge("Varansi", "Indore", 230, false);
	g.addEdge("Mumbai", "Calicut", 300, false);
	g.addEdge("Kashmir", "Kamyakumari", 1350, false);
	g.printAdj();
	return 0;
}