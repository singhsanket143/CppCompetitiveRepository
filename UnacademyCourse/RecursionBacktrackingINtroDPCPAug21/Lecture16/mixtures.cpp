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

std::vector<ll> arr;

ll dp[105][105];
ll g(int i, int j) {
    ll result = 0;
    for(int m = i; m <= j; m++) {
        result = (result%100 + arr[m]%100)%100;
    }
    // log(result);
    return result;
}
ll mix(int i, int j) {
    if(i == j) return dp[i][j] = 0;
    if(dp[i][j] != -1) return dp[i][j];

    ll result = INT_MAX;

    for(int k = i; k <= j-1; k++) {
        result = std::min(result, mix( i,k) + mix(k+1, j) + (g(i,k)*g(k+1, j)));
    }

    return dp[i][j] = result;
}

ll mixBU(int n) {
    std::memset(dp, 0, sizeof dp);

    for(int len = 2; len <= n; len++) {
        for(int i = 0; i <= n-len; i++) {
            int j = i + len - 1;
            ll result = INT_MAX;
            for(int k = i; k <= j-1; k++) {
                result = std::min(result, dp[i][k] + dp[k+1][j] + (g(i,k)*g(k+1, j)));
            }
            dp[i][j] = result;
        }
    }
    return dp[0][n-1];
}


int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    std::memset(dp, -1, sizeof dp);
    int n;
    while(std::cin>>n) {
        // log(n);
        loop(i, 0, n-1) {
            int x;
            std::cin>>x;
            arr.pb(x);
        }
        // logarr(arr, 0, n-1);
        // std::cout<<mix(0, n-1)<<"\n";
        std::cout<<mixBU(n)<<"\n";
        // loop(i, 0, n-1) {
        //     loop(j, 0, n-1) {
        //         std::cout<<dp[i][j]<<" ";
        //     }
        //     std::cout<<"\n";
        // }
        arr.clear();
        std::memset(dp, -1, sizeof dp);
    }

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}