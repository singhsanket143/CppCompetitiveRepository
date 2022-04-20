#include <iostream>
#include <vector>
#include <list>
std::vector<std::list<int> > g;
int disc[100005];
int low[100005];
int dtime;

void dfs(int curr, int par) {
    disc[curr] = dtime;
    low[curr] = dtime;
    dtime++;
    int nc = 0;
    for(auto child : g[curr]) {
        if(disc[child] == 0) {
            dfs(child, curr);
            nc++;
            low[curr] = std::min(low[curr], low[child]);
            if(par != 0 and low[child] >= disc[curr]) {
                std::cout<<"Articulation Point Found "<<curr<<"\n";
            }
            // how can we find bridges ? 
            if(low[child] > disc[curr]) {
                std::cout<<"Bridge Found "<<curr<<" - "<<child<<"\n";
            }
        } else {
            if(child != par) {
                // backedge // cycle
                low[curr] = std::min(low[curr], disc[child]);
            }
        }
    }
    if(par == 0 and nc >= 2) {
        std::cout<<"Articulation Point Found "<<curr<<"\n";
    }
}

int main(int argc, char const *argv[])
{
    int n, m;
    std::cin>>n>>m;
    g.resize(n+1, std::list<int> ());
    for(int i = 0; i < m; i++) {
        int u, v;
        std::cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::memset(disc, 0, sizeof disc);
    //std::memset(low, 0, sizeof low);
    dtime = 1;
    dfs(1, 0);
    return 0;
}
