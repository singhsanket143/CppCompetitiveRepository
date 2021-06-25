// Problem Link - 
/* By Sanket Singh */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define nl				"\n"
#define pb 				push_back
#define eb				emplace_back
#define vi              std::vector<ll>
#define vs				std::vector<std::string>
#define pii             std::pair<ll,ll>
#define ump				std::unordered_map
#define mp 				std::make_pair
#define pq_max          std::priority_queue<ll>
#define pq_min          std::priority_queue<ll,vi,std::greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(std::string str,char ch) {std::istringstream var((str)); vs v; std::string t; while(std::getline((var), t, (ch))) {v.pb(t);} return v;}


void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
    std::cout << *it << " = " << a << std::endl;
    err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<std::string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); 
    std::cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

std::vector<std::vector<int> > graph;

void addEdge(int u, int v) {
    graph[u].pb(v);
    graph[v].pb(u);
}

std::vector<int> sssp(int src, int dest, int n){
    std::vector<bool> visited(n, false);
    std::vector<int> parent(n, -1);
    std::vector<int> dist(n, 0); // stores the shortest path from source to all other ndoes
    std::queue<int> qu;

    qu.push(src);
    visited[src] = true;
    while(not qu.empty()) {
        int node = qu.front();
        qu.pop();
        for(int neighbour: graph[node]) {
            if(not visited[neighbour]) {
                qu.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = node;
                dist[neighbour] = dist[node] + 1;
            }
        }
    }
    int temp = dest;
    std::vector<int> result;
    while(temp != -1) {
        result.pb(temp);
        temp = parent[temp];
    }
    std::reverse(all(result));
    return result;
} // single source shortest path

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    graph.reserve(7);
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(0, 3);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 5);
    addEdge(4, 6);
    addEdge(5, 6);
    addEdge(0, 6);
    std::vector<int> path = sssp(0, 5, 7);
    logarr(path, 0, path.size() - 1);
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}