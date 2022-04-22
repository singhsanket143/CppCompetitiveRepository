#include<vector>
#include<iostream>
const int N = 100;
std::vector<int> gr[N];
int dp[N], vis[N], depth[N];
void dfs(int curr, int par, int dep) {
    vis[curr] = 1;
    dp[curr] = dep;
    depth[curr] = dep;
    for(auto ch : gr[curr]) {
        if(vis[ch] == 0) {
            dfs(ch, curr, dep+1);
            dp[curr] = std::min(dp[curr], dp[ch]);
        } else if(ch != par) {
            // backedge
            dp[curr] = std::min(dp[curr], depth[ch]);
        }
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
