// Problem Link - https://codeforces.com/problemset/problem/383/E
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
}

ll dp[(1<<24)][2];
ll n;
ll form_number(std::string &s) {
    ll res = 0;
    for(auto it : s) {
        res |= (1 << (it - 'a'));
    }
    //log(res);
    return res;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    std::memset(dp, 0, sizeof dp);
    std::cin>>n;
    for(ll i = 1; i <= n; i++) {
        std::string str;
        std::cin>>str;
        dp[(1<<24) - 1][1]++;
        dp[form_number(str)^((1<<24)-1)][1]--;
    }
    // -1 will be stored at index 24
    for(ll i = 23; i >= 0; i--) {
        ll next = (i - 1 + 2) % 2;
        ll j = i%2;
        for(ll mask = 0; mask < (1<<24); mask++) {
            dp[mask][next] = 0;
        }
        for(ll mask = 0; mask < (1 << 24); mask++) {
            if(mask & (1<<i)) {
                dp[mask^(1<<i)][next] += dp[mask][j]; // 1 -> 0 , bit -> !bit
                dp[mask][next] += dp[mask][j]; // bit -> bit
            } else {
                dp[mask][next] += dp[mask][j]; // bit -> bit
            }
        }
    }
    ll ans = 0;
    for(ll i = 0; i < (1 << 24); i++) {
        ans ^= (dp[i][1]*dp[i][1]);
    }
    std::cout<<ans<<"\n";
    
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}