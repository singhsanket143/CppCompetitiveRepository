#include <bits/stdc++.h> 
#define V 10
int graph[V][V];

using namespace std;
int minDistance(int dist[],  
                bool sptSet[]) 
{ 
      
    
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && 
                   dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  
void printPath(int parent[], int j, priority_queue<int> &pq) 
{ 
      
  
    if (parent[j] == - 1) 
        return; 
  
    printPath(parent, parent[j], pq); 
    pq.push(graph[0][j]);
    
} 
  
void printSolution(int dist[], int n, int parent[], int k) 
{ 
    int src = 0;
    int temp=k; 
    for (int i = 1; i < 4; i++) 
    { 
        std::priority_queue<int> mypq;
        printPath(parent, i, mypq); 
        cout<<"for v = "<<i<<" ";
        while(k > 0) {
            cout<<mypq.top()<<" ";
            mypq.pop();
            k=k-1;
        }
        cout<<" after k ";
        int sum = 0;
        while(!mypq.empty()) {
            cout<<mypq.top()<<" ";
            sum+=mypq.top();
            mypq.pop();
        }
        printf("%d\n", sum);
        
        k=temp;
        
    } 
} 

void dijkstra(int graph[V][V], int src, int k) 
{ 
    cout<<k<<endl;
    int dist[V];  
    bool sptSet[V]; 
    int parent[V];  
    for (int i = 0; i < V; i++) 
    { 
        parent[0] = -1; 
        dist[i] = INT_MAX; 
        sptSet[i] = false; 
    } 
    dist[src] = 0; 

    for (int count = 0; count < V - 1; count++) 
    { 

        int u = minDistance(dist, sptSet);  
        sptSet[u] = true; 

        for (int v = 0; v < V; v++) 

            if (!sptSet[v] && graph[u][v] && 
                dist[u] + graph[u][v] < dist[v]) 
            { 
                parent[v] = u; 
                dist[v] = dist[u] + graph[u][v]; 
            }  
    } 
    printSolution(dist, V, parent, k); 
} 

int main() 
{ 
    int n, m, k;
    cin>>n>>m>>k;

    
    
    for(int i=0;i<m;i++) {
        
        int u,v,c;
        cin>>u>>v>>c;
        
        graph[u-1][v-1] = c;
        graph[v-1][u-1] = c;
    }
    dijkstra(graph, 0, k); 
    return 0; 
} 