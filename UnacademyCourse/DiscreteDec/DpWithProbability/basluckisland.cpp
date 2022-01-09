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

ld dp[105][105][105];

ld f(int r, int s, int p) {
    if(r == 0 or s == 0) return 0.0;
    if(p == 0) return 1.0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];
    ld total = r*s + s*p + r*p;
    ld result = 0.0;
    result += f(r-1,s,p)*((r*p)/total);
    result += f(r,s-1,p)*((r*s)/total);
    result += f(r,s,p-1)*((s*p)/total);
    return dp[r][s][p] = result;
}

ld g(int r, int s, int p) {
    if(s == 0 or p == 0) return 0.0;
    if(r == 0) return 1.0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];
    ld total = r*s + s*p + r*p;
    ld result = 0.0;
    result += g(r-1,s,p)*((r*p)/total);
    result += g(r,s-1,p)*((r*s)/total);
    result += g(r,s,p-1)*((s*p)/total);
    return dp[r][s][p] = result;
}

ld h(int r, int s, int p) {
    if(p == 0 or r == 0) return 0.0;
    if(s == 0) return 1.0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];
    ld total = r*s + s*p + r*p;
    ld result = 0.0;
    result += h(r-1,s,p)*((r*p)/total);
    result += h(r,s-1,p)*((r*s)/total);
    result += h(r,s,p-1)*((s*p)/total);
    return dp[r][s][p] = result;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int r, s, p;
    std::cin>>r>>s>>p;
    std::memset(dp, -1, sizeof dp);
    std::cout<<std::fixed<<std::setprecision(9)<<f(r,s,p)<<" ";
    std::memset(dp, -1, sizeof dp);
    std::cout<<std::fixed<<std::setprecision(9)<<g(r,s,p)<<" ";
    std::memset(dp, -1, sizeof dp);
    std::cout<<std::fixed<<std::setprecision(9)<<h(r,s,p)<<" ";


    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}