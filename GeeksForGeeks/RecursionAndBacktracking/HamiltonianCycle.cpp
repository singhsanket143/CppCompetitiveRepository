#include <iostream>
using namespace std;

void printPath(int *path, int v) {
	for(int i=0;i<v;i++) {
		cout<<path[i]<<" ";
	}
}
bool isSafe(int v, int **graph, int *path, int pos) {
	if(graph[path[pos-1]][v] == 0)
		return false;
	for(int i=0;i<pos;i++) {
		if(path[i]==v)
			return false;
	}
	return true;
}
bool hamCycleHelper(int **graph, int *path, int v, int pos) {
	if(pos == v) {
		if(graph[path[pos-1]][path[0]]==1)
			return true;
		else
			return false;
	}
	for(int m=1;m<v;m++) {
		if(isSafe(m, graph, path, pos)){
			path[pos] = m;
			if (hamCycleHelper(graph, path, v, pos + 1) == true) 
	            return true; 
			path[pos] = -1;
		}
	}
	return false;
}
bool hamCycle(int **graph, int v) {
	int *path = new int[v];
	for(int i=0;i<v;i++) {
		path[i] = -1;
	}
	path[0] = 0;
	if(hamCycleHelper(graph, path, v, 1) == false) {
		cout<<"-1";
		return false;
	}
	printPath(path, v);
	return true;
}
int main(int argc, char const *argv[])
{
	int v;
	cin>>v;
	int **graph = new int*[v];
	for(int i=0;i<v;i++) {
		graph[i] = new int[v];
	}
	for(int i=0;i<v;i++) {
		for(int j=0;j<v;j++) {
			cin>>graph[i][j];
		}
	}
	hamCycle(graph, v);
	return 0;
}
