#include<iostream>
#include<vector>
#include<list>

std::vector<std::list<int> > g;

int dp[100005];
int longestPath(int v) { // f(v)
    if(dp[v] != -1) return dp[v];
    int leaf = 1;
    int maxValue = INT_MIN;
    for(auto neighbour : g[v]) {
        leaf = 0;
        maxValue = std::max(maxValue, longestPath(neighbour));
    }

    return dp[v] = ((leaf) ? 0 : (1 + maxValue));
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
    std::memset(dp, -1, sizeof dp);
    int result = INT_MIN;
    for(int i = 0; i < n; i++) {
        result = std::max(result, longestPath(i));
    }
    std::cout<<result;
    return 0;
}
