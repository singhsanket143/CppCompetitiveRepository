#include <bits/stdc++.h>
#include <queue> 
#include <unordered_map>
#include <limits.h> 
using namespace std;

bool bfs(int **residualCapacity, int source, int sink, int n, int *parent) {
	bool visited[n];
	memset(visited, 0, sizeof(visited)); 
	queue <int> que;
	que.push(source);
	visited[source]=true;
	bool foundAugmentedPath = false;
	while(not que.empty()) {
		int u = que.front();
		que.pop();
		for(int v=0;v<n;v++) {
			if(visited[v]==false and residualCapacity[u][v]>0) {
				parent[v] = u;
				visited[v]=true;
				que.push(v);
				if(v==sink) {
					foundAugmentedPath = true;
					break;
				}
			}
		}
	}
	return foundAugmentedPath;
}

void printAugmentedPaths(vector<vector<int> > augmentedPaths) {
	for(int i=0;i<augmentedPaths.size();i++) {
		for(int j=0;j<augmentedPaths[i].size();j++) {
			cout<<augmentedPaths[i][j]<<", ";
		}
		cout<<endl;
	}
}

int maxFlow(int **capacity, int source, int sink, int v) {
	int **residualCapacity = new int*[v];
	for(int i=0;i<v;i++) {
		residualCapacity[i] = new int[v];
	}
	for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                residualCapacity[i][j] = capacity[i][j];
            }
        }
	int *parent = new int[100];
	vector<vector<int> > augmentedPaths;
	int maxFlow = 0;
	while(bfs(residualCapacity, source, sink, v, parent)) {

		vector<int> augmentedPath;
		int flow = INT_MAX;
		int v = sink;
		while(v!=source) {
			augmentedPath.push_back(v);
			int u = parent[v];
			if(flow > residualCapacity[u][v]) {
				flow = residualCapacity[u][v];
			}
			v = u;
		}
		augmentedPath.push_back(source);
		std::reverse(augmentedPath.begin(), augmentedPath.end());
		augmentedPaths.push_back(augmentedPath);
		maxFlow += flow;

		v = sink;
		while(v!=source) {
			int u = parent[v];
			residualCapacity[u][v] -= flow;
            residualCapacity[v][u] += flow;
            v = u;
		}
		//parent.clear();
	}
	printAugmentedPaths(augmentedPaths);
	return maxFlow;
}

int main(int argc, char const *argv[])
{
	/* code */
	int v;
	cin>>v;
	int **Capacity = new int*[v];
	for(int i=0;i<v;i++) {
		Capacity[i] = new int[v];
	}
	int e;
	cin>>e;

	for(int i=0;i<e;i++) {
		int u, v, c;
		cin>>u>>v>>c;
		Capacity[u][v] = c;
	}
	
    cout<<maxFlow(Capacity, 0, 1, v);
	return 0;
}
