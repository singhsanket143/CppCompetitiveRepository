#include<iostream>
#include<vector>
#define ll long long int
#define vi std::vector<ll>

ll get(vi &par, ll i) {
    return par[i] = (par[i] == i) ? i : get(par, par[i]);
}

void Union(vi &par, vi &rank, ll a, ll b) {
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
    vi par(27);
    vi rank(27, 0);
    for(int i = 0; i <= 26; i++) par[i] = i;
    std::vector<bool> total(26, false);

    std::vector<bool> flag(26, false);
    for(int i = 0; i < n; i++) {
        std::string str;
        std::cin>>str;
        flag.clear();
        for(auto ch : str) {
            flag[ch-'a'] = true;
        }
        for(int i = 0 ; i < 26; i++) {
            if(flag[i]) {
                total[i] = true;
                Union(par, rank, str[0]-'a', i);
            }
        }
    }
    int count = 0;
    for(int i = 0; i < 26; i++) {
        if(total[i] and get(par, i) == i) count++;
    }
    std::cout<<count;
    return 0;
}
