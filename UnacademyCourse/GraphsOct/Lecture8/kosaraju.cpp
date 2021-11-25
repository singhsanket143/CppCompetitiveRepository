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
#define us              std::unordered_set
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
    
   
}

std::vector<std::list<int> > g;
std::vector<std::list<int> > gt;

void dfs(int i, us<int> &visited, std::stack<int> &st) { // g
    visited.insert(i);
    for(auto &neighbour : g[i]) {
        if(not visited.count(neighbour)) {
            dfs(neighbour, visited, st);
        }
    }
    st.push(i);
}

void dfs2(int i, us<int> &visited, us<int> &scc) { // gt
    visited.insert(i);
    scc.insert(i);
    for(auto &neighbour : gt[i]) {
        if(not visited.count(neighbour)) {
            dfs2(neighbour, visited, scc);
        }
    }
}
std::vector<us<int> > getSCC(int n, int e) {
    std::stack<int> st;
    us<int> visited;
    for(int i = 0; i < n; i++) {
        if(visited.count(i) == 0) {
            // call dfs
            dfs(i, visited, st);
        }
    }
    //std::cout<<st.size();
    std::vector<us<int> > output;
    visited.clear();
    while(st.size() != 0) {
        int el = st.top();
        st.pop();
        if(visited.count(el) != 0) continue;
        us<int> scc;
        dfs2(el, visited, scc);
        //std::cout<<scc.size()<<"\n";
        output.emplace_back(scc);
    }
    return output;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n, e;
    std::cin>>n>>e;
    g.resize(n, std::list<int>());
    gt.resize(n, std::list<int>());
    for(int i = 0; i < e; i++) {
        int u, v;
        std::cin>>u>>v;
        g[u].pb(v);
        gt[v].pb(u);
    }
    std::vector<us<int> > scc = getSCC(n, e);
    for(auto &s : scc) {
        for(auto &el : s) {
            std::cout<<el<<",";
        }
        std::cout<<"\n";
    }

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}