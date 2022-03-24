#include<iostream>
#include<vector>
#include<list>

std::vector<std::list<std::pair<int, int> > > g;

int holi(int v, std::vector<bool> &vis, std::vector<int> &count, int n, int &ans) { // f(v)
    vis[v] = true;
    count[v] = 1;
    for(auto &neighbour : g[v]) {
        int weight = neighbour.second;
        if(not vis[neighbour]) {
            count[v] += holi(neighbour, vis, count, n, ans);
            ans += 2*(count[v], n-count[v])*weight;
        }
    }
    return count[node];
}

int dfs(int n) {
    std::vector<bool> vis(n, false);
    std::vector<int> count(n, 0);
    ll ans = 0;
    holi(0, vis, count, n, ans);
    return ans;

}

int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    g.resize(n, std::list<int> ());
    int m;
    std::cin>>m;
    while(m--) {
        int u, v;
        std::cin>>u>>v;
        u--;
        v--;
        g[u].push_back(v);
    }
    
    return 0;
}
