#include <iostream>
#include<list>
using namespace std;


class Graph{
    
    int V;
    list<int> *l;
    
    public:
        Graph(int v){
            V = v;
            l = new list<int>[V];
            
        }
        
        void addEdge(int u,int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }
        void dfsHelper(int i,bool visited[],int &country_size){
            visited[i] = true;
            country_size++;
            
            for(auto neighbour:l[i]){
                if(!visited[neighbour]){
                    dfsHelper(neighbour,visited,country_size);
                }
            }
            
        }
        
        int dfsMoon(){
            bool *visited = new bool[V];
            for(int i=0;i<V;i++){
                visited[i] = false;
            }
            
            int n = V;
            int total_ways = (n)*(n-1)/2;
            
            for(int i=0;i<V;i++){
                if(visited[i]==false){
                    int country_size = 0;
                    dfsHelper(i,visited,country_size);
                    //cout<<"Country Size "<<country_size<<endl;
                    total_ways -= (country_size)*(country_size-1)/2;
                }
            }
            
            return total_ways;   
        }
    
    
};



int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(2,3);
    g.addEdge(0,4);
    
    cout<<g.dfsMoon();
}
