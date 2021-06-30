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

// basic recursive solution
// ll f(int n) {
//     if(n == 1) return 0;
//     if(n == 2 or n == 3) return 1;
//     ll ans = inf;
//     if(n%2 == 0) {
//         ans = std::min(ans, f(n/2));
//     }
//     if(n%3 == 0) {
//         ans = std::min(ans, f(n/3));
//     }
//     ans = std::min(ans, f(n-1));

//     if(ans < inf) {
//         return 1+ans;
//     } else {
//         return ans;
//     }
// }


// Top down dp
std::vector<ll> dp;
ll f(int n) {
    if(n == 1) return 0;
    if(n == 2 or n == 3) return 1;
    if(dp[n] != -1) return dp[n];
    ll ans = inf;
    if(n%2 == 0) {
        ans = std::min(ans, f(n/2));
    }
    if(n%3 == 0) {
        ans = std::min(ans, f(n/3));
    }
    ans = std::min(ans, f(n-1));

    if(ans < inf) {
        return dp[n] = 1+ans;
    } else {
        return dp[n] = ans;
    }
}


ll fbu(int n) {
    std::vector<ll> dp(n+1, -1);
    dp[1] = 0;
    dp[2] = dp[3] = 1;
    for(int i = 4; i <= n; i++) {
        ll div_by_2 = inf;
        ll div_by_3 = inf;
        ll sub_by_1 = inf;
        if(i%3 == 0) {
            div_by_3 = dp[i/3];
        }
        if(i%2 == 0) {
            div_by_2 = dp[i/2];
        }
        sub_by_1 = dp[i-1];
        dp[i] = 1 + std::min({sub_by_1, div_by_2, div_by_3});
    }
    return dp[n];
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n = 7;
    dp.resize(n+1);
    std::fill(dp.begin(), dp.end(), -1);
    std::cout<<f(n)<<" "<<fbu(n);

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}