#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &parent, int x) {
    // TX:(log*n);
    // This method returns which group/cluster x belongs to
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

void Union(vector<int> &parent, vector<int> &rank, int a, int b) {
    // TX:(log*n);
    a = find(parent, a);
    b = find(parent, b);
    if(a == b) return;
    if(rank[a] >= rank[b]) {
        rank[a]++;
        parent[b] = a;
    } else {
        rank[b]++;
        parent[a] = b;
    }
}


int main() {

    int n, m;
    cin>>n>>m;
    // n-> elements, m -> no of queries
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);
    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    while(m--) {
        string str;
        cin>>str;
        if(str == "union") {
            int x, y;
            cin>>x>>y;
            Union(parent, rank, x, y);
        } else {
            int x;
            cin>>x;
            cout<<find(parent, x)<<"\n";
        }
    }

    return 0;
}