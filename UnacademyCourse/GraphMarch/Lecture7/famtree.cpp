#include <iostream>
#include <vector>
#define ll long long int
ll ma[100005], mi[100005];
ll w[100005], p[100005];
std::vector<std::vector<ll> > tree;
ll ans = 0;
void famtree(ll root, ll par) {
    for(ll child : tree[root]) {
        if(child != par) {
            famtree(child, root);
            ma[root] = std::max(ma[root], ma[child]);
            mi[root] = std::min(mi[root], mi[child]);
        }
    }

    ma[root] = std::max(ma[root], w[root]);q
    mi[root] = std::min(mi[root], w[root]);
    ans = std::max(ans, std::abs(w[root] - ma[root]));
    ans = std::max(ans, std::abs(w[root] - mi[root]));
}

int main(int argc, char const *argv[])
{
    ll n;
    std::cin>>n;
    tree.resize(n, std::vector<ll> ());
    for(int i = 1; i <= n; i++) {
        ma[i] = INT_MIN;
        mi[i] = INT_MAX;
    }
    ll root = 0;
    for(int i = 1; i <= n; i++) {
        std::cin>>w[i];
    }
    for(int i = 1; i <= n; i++) {
        std::cin>>p[i];
        if(p[i] == -1) {
            root = i;
        } else {
            tree[p[i]].push_back(i);
        }
    }
    famtree(root, 0);
    std::cout<<ans<<"\n";
    return 0;
}
