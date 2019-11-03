/*
	261. Graph Valid Tree

	Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

	Example 1:
	Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
	Output: true

	Example 2:
	Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
	Output: false

	Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.

*/
#include <iostream>
using namespace std;

class Solution {
public:
    bool cycle(int node, unordered_map<int, bool> &visited, int parent, unordered_map<int, list<int> > &adj) {
        visited[node] = true;
        for(int neighbour: adj[node]) {
            if(!visited[neighbour]) {
                bool isTree = cycle(neighbour, visited, node, adj);
                if(!isTree) {
                    return false;
                }    
            } else if(neighbour!=parent) {
                return false;
            }
        }
        return true;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, list<int> > adj;
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_map<int, bool> visited;
            int node = 0;
            if(!visited[node]) {
                int ans = cycle(node, visited, node, adj);
                if(!ans) {
                    return false;
                }
            }
        return visited.size() == n;
    }
};