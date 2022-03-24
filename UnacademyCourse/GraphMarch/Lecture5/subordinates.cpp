#include<iostream>
#include<vector>
#include<list>

std::vector<std::list<int> > g;

int dp[100005];
int subordinates(int v, int par) { // f(v)
    if(dp[v] != -1) return dp[v];
    int ans = 0;
    for(auto emp : g[v]) {
        if(emp != par) {
            int x = subordinates(emp, v);
            ans += (1+x);
        }
    }
    return dp[v] = ans;
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
