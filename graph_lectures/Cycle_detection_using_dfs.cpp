#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

vector<list<int> > graph;
int v; // no of vertices
void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if(bi_dir) {
        graph[dest].push_back(src);
    }

}

void display() {
    for(int i = 0; i < graph.size(); i++) {
        cout<<i<<" -> ";
        for(auto el : graph[i]) {
            cout<<el<<" , ";
        }
        cout<<"\n";
    }
}

bool dfs(int src, int parent, unordered_set<int> &vis) {
    vis.insert(src);
    for(auto neighbour : graph[src]) {
        if(vis.count(neighbour) and neighbour != parent) {
            // cycle detected
            return true;
        }
        if(!vis.count(neighbour)) {
            bool res = dfs(neighbour, src, vis);
            if(res == true) return true;
        }
    } 
    return false;
}

bool has_cycle() {
    unordered_set<int> vis;
    for(int i = 0; i < v; i++) {
        if(!vis.count(i)) {
            bool result = dfs(i, -1, vis);
            if(result == true) return true;
        }
    }
    return false;
}

int main() {

    cin>>v;
    graph.resize(v, list<int> ());
    int e;
    cin>>e;
    while(e--) {
        int s, d;
        cin>>s>>d;
        add_edge(s, d, false);
    }
    // display();
    bool b = has_cycle();
    cout<<b<<"\n";

    return 0;
}