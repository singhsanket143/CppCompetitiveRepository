#include "bits/stdc++.h"
#define ll long long int
using namespace std;

class Graph {
    int V;
    list<pair<int, int> > *l;
public:
    Graph(int v) {
        V = v;
        l = new list<pair<int, int> >[V];
    }
    void addEdge(int u, int v, int cost, bool bidir = true) {
        l[u].push_back(make_pair(v, cost));
        if(bidir) {
            l[v].push_back(make_pair(u, cost));
        }
    }
    int dfsHelper(int node, bool *visited, int *count, ll &ans) {
        visited[node] = true;
        count[node] = 1;
        for(auto neighbour:l[node]) {
            int v=neighbour.first;
            if(!visited[v]) {
                count[node] += dfsHelper(v, visited,count, ans);
                ans += 2*min(count[v], V-count[v])*neighbour.second;
            }
        }
        return count[node];
    }
    int dfsMain() {
        bool *visited = new bool[V];
        int *count = new int[V];
        for(int i=0;i<V;i++) {
            visited[i]=false;
            count[i]=0;
        }
        ll ans = 0;
        dfsHelper(0, visited, count, ans);
        return ans;
    }
};

int main(int argc, char* argv[])
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++) {
        int n;
        cin>>n;
        Graph g(n);
        while(n-- > 1) {
            int a,b,c;
            cin>>a>>b>>c;
            g.addEdge(a-1,b-1,c);
        }
        cout<<"Case #"<<(i+1)<<": "<<g.dfsMain()<<'\n';
    }

    return 0;
}
