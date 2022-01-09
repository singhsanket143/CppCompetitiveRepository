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
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}

ll n, m;
ll dp[105][105][105];

ll dx1[] = {1, 1, 0, 0};
ll dx2[] = {1, 0, 1, 0};
ll dy1[] = {0, 0, 1, 1};
ll dy2[] = {0, 1, 0, 1};

char ch[105][105];

ll f(ll x1, ll y1, ll x2) {
    ll y2 = x1 + y1 - x2;
    if(x1 > n or y1 > m or x2 > n or y2 > m or ch[x1][y1] == '#' or ch[x2][y2] == '#') return -inf;
    if(x1 == n and y1 == m) {
        return (ch[x1][y1] == '*');
    }
    if(dp[x1][y1][x2] != -1) return dp[x1][y1][x2];
    ll result = -inf;
    for(int i = 0; i < 4; i++) {
        result = std::max(result, f(x1 + dx1[i], y1 + dy1[i], x2 + dx2[i]));
    }
    result += (ch[x1][y1] == '*');
    result += (ch[x2][y2] == '*');
    if(x1 == x2 and y1 == y2 and ch[x2][y2] == '*') result--;
    return dp[x1][y1][x2] = result;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    ll t;
    std::cin>>t;
    while(t--) {
        std::cin>>m>>n;
        std::memset(dp, -1, sizeof dp);
        loop(i, 1, n) {
            loop(j, 1, m) {
                std::cin>>ch[i][j];
            }
        }
        std::cout<<f(1,1,1)<<"\n";
    }

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}