#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
#define pp std::pair<int, int> 
#define ff first
#define ss second
std::vector<std::list<pp> > g;

std::unordered_map<int, bool> vis;
std::unordered_map<int, int> mp;
std::priority_queue<pp, std::vector<pp>, std::greater<pp> > pq;

void dijkstra(int n) {
    pq.push({0, 0});
    for(int i = 0; i < n; i++) {
        mp[i] = INT_MAX;
    }
    mp[0] = 0;
    while(not pq.empty()) {
        int curr = pq.top().ss;
        if(vis.find(curr) != vis.end()) {
            pq.pop();
            continue;
        }
        vis[curr] = true;
        pq.pop();
        for(auto neigh : g[curr]) {
            if(mp[curr] + neigh.ss < mp[neigh.ff]) {
                mp[neigh.ff] = mp[curr] + neigh.ss;
                pq.push({mp[neigh.ff],neigh.ff});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int n,m;
    std::cin>>n>>m;
    g.resize(n, std::list<pp> ());
    for(int i = 0; i < m; i++) {
        int u, v, w;
        std::cin>>u>>v>>w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dijkstra(n);
    for(auto el : mp) {
        std::cout<<el.ff<<" "<<el.ss<<"\n";
    }
    return 0;
}
