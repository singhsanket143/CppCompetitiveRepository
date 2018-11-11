#include <iostream>
#include <algorithm>
using namespace std;

class Edge {
public:
	int src;
	int dest;
	int weight;
};

class Set {
public:
	int rank;
	int parent;
};

int find(Set *set, int i) {
	if(set[i].parent != i) {
		set[i].parent = find(set, set[i].parent);
	}
	return set[i].parent;
}

void Union(Set *set, int v1, int v2) {
	int v1_root = find(set, v1);
	int v2_root = find(set, v2);
	if(set[v1_root].rank < set[v2_root].rank) {
		set[v1_root].parent = v2_root;
	} else if(set[v1_root].rank > set[v2_root].rank) {
		set[v2_root].parent = v1_root;
	} else {
		set[v2_root].parent = v1_root;
		set[v1_root].rank++;
	}
}

bool cmp(Edge e1, Edge e2) {
	return e1.weight < e2.weight;
}

void Kruskals(Edge *input, int n, int e) {
	sort(input, input+e, cmp); // It will sort the input array on the basis of the weights of the edges
	Edge *output = new Edge[n-1]; // initialised an output array
	Set *set = new Set[n]; // Initialised the sets for all vertices
	for(int i=0;i<n;i++) {
		set[i].rank = 0; // Assign the rank initially as 0
		set[i].parent = i; // Assisned the parent of all vertices that are iitially in their individual set as the vertex
	}
	int counter = 0, i = 0;
	while(counter<n-1) { 
		Edge currentEdge = input[i]; // We have takenn the edge with minimum weight
		int sourceParent = find(set, currentEdge.src); // Found the parent of source vertex
		int destinationParent = find(set, currentEdge.dest); // Found the parent of destination vertex
		if(sourceParent != destinationParent) { // If both these lie in the same Set or not
			output[counter] = currentEdge; // We will insert the edge in mst
			Union(set, sourceParent, destinationParent); // THen we willunion the sets of the src and dest vertex
			counter++; // increase the counter
		}
		i++;
	}

	// for(int m=0;m<n-1;m++) {
	// 	cout<<output[m].src<<"--"<<output[m].dest<<" with weight "<<output[m].weight<<endl;
	// }
	int totalWeight = 0;
	for(int m=0;m<n-1;m++) {
		// cout<<output[m].src<<"--"<<output[m].dest<<" with weight "<<output[m].weight<<endl;
		totalWeight+=output[m].weight;
	}
	cout<<totalWeight<<endl;

}

int main(int argc, char const *argv[])
{
	int n, e;
	cin>>n>>e;
	Edge *input = new Edge[e];
	for(int i=0;i<e;i++) {
		int s, d, w;
		cin>>s>>d>>w;
		input[i].src = s;
		input[i].dest = d;
		input[i].weight = w;
	}
	Kruskals(input, n, e);
	return 0;
}
