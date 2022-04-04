#include<iostream>
#include<vector>
#define ll long long int
#define vi std::vector<ll>

ll get(vi &par, ll i) {
    return par[i] = (par[i] == i) ? i : get(par, par[i]);
}

void union(vi &par, vi &rank, ll a, ll b) {
    a = get(par, a);
    b = get(par, b);
    if(rank[a] == rank[b]) {
        rank[a]++;
    } 
    if(rank[a] > rank[b]) {
        par[b] = a;
    } else {
        par[a] = b;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    vi par(n+1);
    vi rank(n+1, 0);
    for(int i = 0; i <= n; i++) par[i] = i;
    return 0;
}
