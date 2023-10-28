#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    bool bfs(int src, vector<int> &color, int n, vector<vector<int>>& graph) {
        queue<int> qu;
        
        qu.push(src);
        color[src] = 0;
        while(not qu.empty()) {
            int curr = qu.front();
            qu.pop();
            for(auto neighbour : graph[curr]) {
                if(color[neighbour] == -1) {
                    color[neighbour] = !color[curr];
                    qu.push(neighbour);
                } else if(color[curr] == color[neighbour]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < graph.size(); i++) {
            if(color[i] == -1) {
                if(bfs(i, color, n, graph) == false) return false;
            }
        }
        return true;
    }
};
int main() {

    return 0;
}