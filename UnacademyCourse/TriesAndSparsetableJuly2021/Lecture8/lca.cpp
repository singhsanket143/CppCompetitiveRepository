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

const int N = 100005, M = 22;
int table[N][M];
std::vector<int> graph[N];
int parent[N], depth[N] = {0};

void dfs(int curr, int p) {
    parent[curr] = p;
    for(auto neighbour: graph[curr]) {
        if(neighbour != p) {
            depth[neighbour] = 1 + depth[curr];
            dfs(neighbour, curr);
        }
    }
}
// O(n)
int lca_two_pointer(int x, int y) {
    if(x == y) return x;
    if(depth[x] < depth[y]) std::swap(x, y);
    // always depth of x is more
    while(depth[x] > depth[y]) {
        x = parent[x];
    }
    while(x != y) {
        x = parent[x];
        y = parent[y];
    }
    return x;
}

void preprocess_sparse_table(int curr, int p) {
    table[curr][0] = p;
    for(int j = 1; j < M; j++) {
        table[curr][j] = table[table[curr][j-1]][j-1];
    }
    for(auto neighbour : graph[curr]) {
        if(neighbour != p) {
            depth[neighbour] = 1 + depth[curr];
            preprocess_sparse_table(neighbour, curr);
        }
    }
}

int lca_with_sparse(int x, int y) {
    if(x == y) return x;
    if(depth[x] < depth[y]) std::swap(x, y);
    int diff = depth[x] - depth[y];
    for(int i = M-1; i>= 0; i--) {
        if((diff >> i) & 1) {
            x = table[x][i];
        }
    }

    if(x == y) return x;

    for(int i = M-1; i >= 0; i--) {
        if(table[x][i] != table[y][i]) {
            x = table[x][i];
            y = table[y][i];
        }
    }
    return table[x][0];
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n;
    std::cin>>n;
    for(int i = 1; i < n; i++) {
        int x, y;
        std::cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    // dfs(1, 0);
    preprocess_sparse_table(1, 0);
    // for(int i = 1; i <= n; i++) {
    //     log(i, depth[i], parent[i]);
    // }
    std::cout<<lca_with_sparse(8, 12)<<"\n";

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}