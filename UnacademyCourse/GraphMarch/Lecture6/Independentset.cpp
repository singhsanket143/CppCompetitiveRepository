#include<iostream>
#include<vector>
#include<list>
#define ll long long int
#define mod 1000000007
std::vector<std::list<int> > tree;
int dp[100005][2];

ll independentset(int node, int c, int par) {
    if(dp[node][c] != -1) return dp[node][c];

    ll ans = 0;
    ll ways0 = 1;

    for(auto child : tree[node]) {
        if(child != par) {
            ways0 = (ways0 * independentset(child, 0, node)) % mod;
        }
    }
    ans += ways0;
    if(c == 0) { // no constraint that means painted white
        ll ways1 = 1;
        for(auto child : tree[node]) {
            if(child != par) {
                ways1 = (ways1 * independentset(child, 1, node)) % mod;
            }
        }
        ans += ways1;
    }
    return dp[node][c] = ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    std::cin>>n;
    tree.resize(n, std::list<int> ());
    std::memset(dp, -1, sizeof dp);
    for(int i = 1; i <= n-1; i++) {
        int x, y;
        std::cin>>x>>y;
        x--;
        y--;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    std::cout<<independentset(0, 0, -1)<<"\n";
    return 0;
}
