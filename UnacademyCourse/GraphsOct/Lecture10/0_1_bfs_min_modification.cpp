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
std::vector< std::vector<std::pair<int, int> > > g;
int label(int i, int j, char d, int n, int m) {
    if(d == 'U') {
        i--;
    } else if (d == 'L') {
        j--;
    } else if(d == 'R') {
        j++;
    } else if(d == 'D') {
        i++;
    }
    if(i < 0 or j < 0 or i >= n or j >= m) return -1;
    return (i*m + j);
}
char dir(int x) {
    if(x == 0) return 'L';
    if(x == 1) return 'U';
    if(x == 2) return 'R';
    if(x == 3) return 'D';

}
int bfs(int n, int m) {
    std::deque<int> qu;
    std::vector<int> dist(n*m, INT_MAX);
    int src = 0, dest = (n-1)*m + (m-1);
    dist[src] = 0;
    qu.pb(src);
    while(not qu.empty()) {
        int curr = qu.front();
        qu.pop_front();
        for(auto n : g[curr]) {
            if(dist[n.ff] > dist[curr] + n.ss) {
                dist[n.ff] = dist[curr] + n.ss;
                if(n.ss == 0) {
                    qu.push_front(n.ff);
                } else {
                    qu.pb(n.ff);
                }
            }
        }
    }
    return dist[dest];
}
int min_modifications(std::vector<std::vector<char> > &mat, int n, int m) {
    g.resize(n*m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int d = 0; d < 4; d++) {
                int l = label(i, j, dir(d), n, m);
                if(l == -1) continue;
                if(dir(d) == mat[i][j]) {
                    g[i*m+j].pb({l, 0});
                } else {
                    g[i*m+j].pb({l, 1});
                }
            }
        }
    }
    // for(auto &v : g) {
    //     for(auto &el : v) {
    //         std::cout<<el.ff<<"->"<<el.ss<<" , ";
    //     }
    //     std::cout<<"\n";
    // }
    return bfs(n, m);
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n, m;
    std::cin>>n>>m;
    std::vector<std::vector<char> > mat(n, std::vector<char> (m, ' '));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin>>mat[i][j];
        }
    }
    std::cout<<min_modifications(mat, n, m)<<"\n";
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}