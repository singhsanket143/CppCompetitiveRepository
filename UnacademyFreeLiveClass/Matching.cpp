#include<iostream>
#include<vector>
#include<cstring>
#define ll long long int
#define mod 1000000007

ll dp[22][(1<<22)];
ll f(std::vector<std::vector<int> > compat, int i, int mask, int n) {
    if(i == n+1) {
        if(mask == 0) return 1; // one possible way found
        return 0; // no possible way found for this branch
    }
    if(dp[i][mask] != -1) return dp[i][mask];
    ll ans = 0;
    for(int w = 0; w < n; w++) {
        bool avail = (((1 << w)&(mask)) == 0) ? 0 : 1;
        if(avail and compat[i][w+1] == 1) {
            ans = ((ans%mod) + (f(compat, i+1, mask^(1<<w) , n)%mod))%mod;
        }
    }

    return dp[i][mask] = ans;
}

int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::vector<std::vector<int> > compat(n+1, std::vector<int> (n+1));
    std::memset(dp, -1, sizeof dp);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            std::cin>>compat[i][j];
        }
    }
    std::cout<<f(compat, 1, (1<<n)-1, n);
    return 0;
}
