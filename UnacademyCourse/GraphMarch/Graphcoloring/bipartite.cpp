#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>

std::vector<std::vector<int> > g;
void addedge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}

bool isbipartite(int src) {
    std::unordered_set<int> sets[2];
    std::queue<int> qu;
    sets[0].insert(src);
    qu.push(src);
    while(not qu.empty()) {
        int curr = qu.front();
        qu.pop();
        int c = (sets[0].count(curr) > 0) ? 0 : 1;
        for(auto n : g[curr]) {
            if(sets[0].count(n) == 0 and sets[1].count(n) == 0) {
                qu.push(n);
                sets[1-c].insert(n);
            } else if(sets[c].count(n) > 0) return false;
        }
    }
    return true;
}

int main() {
    int v, e;
    std::cin>>v>>e;
    g.resize(v);
    while(e--) {
        int u, v;
        std::cin>>u>>v;
        addedge(u, v);
    }
    std::cout<<(isbipartite(0) == 1) ? "Yes" : "No";
    return 0;
}