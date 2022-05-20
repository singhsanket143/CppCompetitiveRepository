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

class edge {
public:
    int src;
    int dest;
    int wt;
};

bool cmp(edge e1, edge e2) {
    return e1.wt < e2.wt;
}

void kruskals(std::vector<edge> &input, int n, int e) {
    std::sort(input.begin(), input.end(), cmp);
    std::vector<edge> output;
    vi par(n+1);
    vi rank(n+1, 0);
    for(int i = 0; i <= n; i++) par[i] = i;
    int counter = 0, i = 0;
    while(counter < n-1) {
        edge currentedge = input[i];
        int srcparent = get(par, currentedge.src);
        int destparent = get(par, currentedge.dest);
        if(srcparent != destparent) {
            output.emplace_back(currentedge);
            Union(par, rank, srcparent, destparent);
            counter++;
        }
        i++;
    }
    int total_weight = 0;
    for(int m = 0; m < counter; m++) {
        total_weight+=output[m].wt;
    }
    std::cout<<total_weight<<"\n";
}

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    std::cin>>n;
    
    return 0;
}
