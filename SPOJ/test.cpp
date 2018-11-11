#include <iostream>
#include <iomanip>
#include <list>
using namespace std;
#define ll long double 
#define inf 1e9

class Graph {
    int v;
    list<pair<int, int> > *adj;

public:
    Graph(int v) {
        this->v = v;
        adj = new list<pair<int, int> >[v];
    }

    void addEdge(int u, int v, int w, bool bidir = true) {
        adj[u].push_back(make_pair(v, w));
        if(bidir) {
            adj[v].push_back(make_pair(u, w));
        }
    }

    int findminVertex(int *weight, bool *visited, int v) {
        int minVertex = -1;
        for(int i=0;i<v;i++) {
            if(!visited[i] and (minVertex == -1 or weight[i] < weight[minVertex])) {
                minVertex = i;
            }
        }
        return minVertex;
    }

    void prims() {
        int *parent = new int[v];
        int *weight = new int[v];
        bool *visited = new bool[v];
        for(int i=0;i<v;i++) {
            visited[i] = false;
            weight[i] = inf;
        }
        parent[0] = -1;
        weight[0] = 0;

        for(int i=0;i<v;i++) {
            int minVertex = findminVertex(weight, visited, v);
            visited[minVertex] = true;
            for(auto neighbour:adj[minVertex]) {
                if(!visited[neighbour.first]) {
                    if(weight[neighbour.first] > neighbour.second) {
                        weight[neighbour.first] = neighbour.second;
                        parent[neighbour.first] = minVertex;
                    }
                }
            }
        }

        // for(int i=1;i<v;i++) {
        //  cout<<i<<"--"<<parent[i]<<" with weight "<<weight[i]<<endl;
        // }
        int totalWeight = 0;
        for(int i=1;i<v;i++) {
            totalWeight+=weight[i];
        }
        cout<<totalWeight<<endl;
    }
};

int fact(int n) {
    if(n==0 or n==1) {
        return 1;
    }
    return n*fact(n-1);
}

int fib(int n) {
    if(n==0 or n==1) {
        return n;
    }
    return fib(n-1)+fib(n-2);
}

ll fun(long long int n,long long int m) {
    fact(4);
    int temp=1;
    for(int i=1;i<4;i++) {
        temp*=i;
        temp%=100000;
        temp++;
    }
    if(n==4){
        if(m>=2){
            fact(4);
            return 1.0000000;
        }
    }
    if((n==2 or n==3) and m==1){
        fib(2);
        return 0.50000000;
    }
 
    if(n==1){
        fib(3);
        return 1.0000000;
    }
    if(m==0){
        fact(4);
        return (ll)1/(ll)n;
    }
    if(n==3){
        return 1.00000000;
    }
    if(n%2==0){
        fact(4);
        return fun(n/2,m-1);
    }
    return fun(n/2+1,m-1);
}

int modRecursive(int a,int b,int c){
    if(b == 0){
        return 1;
    }

    if(b%2 ==0){

        return modRecursive((a*a)%c,b/2,c);
    }else{
        return ((a%c)*(modRecursive((a*a)%c,b/2,c)))%c;
    }

}

int main()
{
    long long int t;
    scanf("%lld", &t);
    while(t--){
        long long int n,m;
        scanf("%lld", &n);
        scanf("%lld", &m);
        int temp=1;
        for(int i=1;i<4;i++) {
        temp*=i;
        temp%=100000;
        temp++;
        }
        if(m==1){
            if(n==1){
                fact(4);
                printf("1.000000\n");
                
            }
            else if(n<=4){
                fib(2);
                printf("0.5000000\n");
     
            }
            else if(n%4==0 and m==1){
                fact(4);
                cout<<fixed<<setprecision(6)<<fun(n/2,0)<<endl;
            }
            else cout<<fixed<<setprecision(6)<<fun(n/2+1,0)<<endl;
            
        }
        else if(m==0){
            fib(2);
            ll an = (ll)1/(ll)n;
            fact(4);
            fib(4);
            cout<<fixed<<setprecision(6)<<an<<endl;
            fact(2);
        }
        else
            cout<<fixed<<setprecision(6)<<fun(n,m)<<endl;

    }
    return 0;
}