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
    
}

ll dp[2005][2005][2][2][2];
int m;
std::string a, b, s;
int d;
ll f(ll pos, ll mo, bool tight, bool st, bool even, std::string str) {
    if(pos == s.size()) {
        if(mo == 0) std::cout<<str<<"\n";
        return mo == 0;
    }
    if(dp[pos][mo][tight][st][even] != -1) return dp[pos][mo][tight][st][even];

    ll ans = 0; 
    ll limit = (tight) ? (s[pos] - '0') : 9;
    if(st == 0) {
        ans = (ans + f(pos+1, mo, tight & (s[pos] == '0'), st, 0, str))%mod;
        for(ll i = 1; i <= limit; i++) {
            if(i != d)
                ans = (ans + f(pos+1, (mo*10 + i)%m, tight & (i == limit), 1, 1, str + std::to_string(i)))%mod;

        }
    } else  {
        for(ll i = 1; i <= limit; i++) {
            if(even and (i == d)) {
                ans = (ans + f(pos+1, (mo*10 + i)%m, tight & (i == limit), 1, !even, str + std::to_string(i)))%mod;
            } else if((!even) and (i != d)) {
                ans = (ans + f(pos+1, (mo*10 + i)%m, tight & (i == limit), 1, !even, str + std::to_string(i)))%mod;
            }
        }
    }
    return dp[pos][mo][tight][st][even] = ans;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    std::cin>>m>>d;
    std::cin>>a>>b;
    std::memset(dp, -1, sizeof dp);
    s = b;
    ll ans = f(0, 0, 1, 0, 0, "");
    log("--------", ans);
    std::memset(dp, -1, sizeof dp);
    s = a;
    ans = (ans - f(0, 0, 1, 0, 0, "") + mod) % mod;


    bool flag = 1;
    ll mo = 0;
    for(ll i = 0; i < a.size() ; i++) {
        int pos = i+1;
        if(pos%2 and ((a[i] - '0') == d)) { // pos odd, 
            flag = 0;
        }
        if(pos%2 == 0  and ((a[i] - '0') != d)) { // pos even 
            flag = 0;
        }
        mo = (mo*10 + (a[i] - '0'))%m;
    }
    if(mo==0 and flag) {
        ans = (ans + 1) % mod;
    }

    std::cout<<ans<<"\n";

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}