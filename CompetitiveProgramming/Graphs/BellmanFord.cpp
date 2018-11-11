#include <iostream>
#include <list>
#include <queue>
#include <map>
#define inf 1e9
using namespace std;

class Edge {
public:
     int src, dest, weight;
};

class Graph {
	int v, e;
	Edge *edge;

public:
	Graph(int v, int e) {
		this->v = v;
          this->e = e;
		edge = new Edge[e];
	}

	void addEdge(int u, int v, int w,int count, bool bidir = true) {
		edge[count].src = u;
          edge[count].dest = v;
          edge[count].weight = w;
	}

     void print() {
          for(int i=0;i<e;i++) {
               cout<<edge[i].src<<" "<<edge[i].dest<<" "<<edge[i].weight<<endl;;
          }
     }

     void BellmanFord(int src) {
          int distance[v];
          for(int i=0;i<v;i++) {
               if(i==src)
                    distance[i] = 0;
               else
                    distance[i] = inf;
          }
          for(int i=1;i<=v-1;i++) {
               for(int j=0;j<e;j++) {
                    int src = edge[j].src;
                    int dest = edge[j].dest;
                    int wt = edge[j].weight;
                    if(distance[src] != inf and distance[src]+wt < distance[dest]) {
                         distance[dest] = distance[src] + wt;
                    }
               }
          }

          // For negative weight cycle
          for (int i = 0; i < e; i++) { 
             int src = edge[i].src; 
             int dest = edge[i].dest; 
             int wt = edge[i].weight; 
             if (distance[src] != inf && distance[src] + wt < distance[dest]) {
                 printf("Graph contains negative weight cycle from %d to %d", src, dest); 
                 return;
            }
          } 

          // print distance
          for (int i = 0; i < v; ++i) 
               printf("%d - %d\n", i, distance[i]); 
          return;
     }

};

int main(int argc, char const *argv[])
{
     int n, e;
     cin>>n>>e;
	Graph g(n, e);
	for(int i=0;i<e;i++) {
          int u, v, w;
          cin>>u>>v>>w;
          g.addEdge(u, v, w, i);
     }
     // g.print();
     g.BellmanFord(0);
	return 0;
}
