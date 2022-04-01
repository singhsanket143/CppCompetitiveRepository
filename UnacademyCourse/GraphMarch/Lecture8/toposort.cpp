#include<iostream>
#include<queue>
#include<vector>
#include<list>

std::vector<std::list<int> > g;

void topologicalSort(int v) {
    std::vector<bool> visited(v, false);
    std::vector<int> indegree(v, 0);
    for(auto i : g) {
        for(auto v : i) {
            indegree[v]++;
        }
    }
    std::queue<int> qu;
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) qu.push(i);
    } 
    while(not qu.empty()) {
        auto node = qu.front();
        qu.pop();
        std::cout<<node<<" ";
        for(auto neigh: g[node]) {
            indegree[neigh]--;
            if(indegree[neigh] == 0) {
                qu.push(neigh);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    std::cin>>n;
    g.resize(n, std::list<int> ());
    int m;
    std::cin>>m;
    while(m--) {
        int u, v;
        std::cin>>u>>v;
        g[u].push_back(v);
    }
    topologicalSort(n);
    return 0;
}
