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

std::vector<int> wt;
std::vector<int> val;
int MW;
int n;
int dp[105][100005];

int knapsack(int i, int j) {
    
    if(i == 0 or j <= 0) {
        return 0;
    }
    if(dp[i][j] != -1) return dp[i][j];

    int result = 0;
    if(wt[i] <= j) {
        // pick or not pick
        int v1 = knapsack(i-1, j); // not pick
        int v2 = knapsack(i-1, j - wt[i]) + val[i]; // pick
        result = std::max(v1, v2);
    } else {
        // not pick
        result = knapsack(i-1, j); // not pick
    }
    return dp[i][j] = result;
}


ll knapsackBU1(int n, int mW) {
    // TC - O(nMW) SC - O(nMW)
    std::vector<std::vector<ll> > dp(n+1, std::vector<ll> (mW+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= mW; j++) {
            dp[i][j] = dp[i-1][j];
            if(wt[i] <= j) {
                dp[i][j] = std::max(dp[i][j], val[i] + dp[i-1][j-wt[i]]);
            }
        }
    }
    return dp[n][mW];
}

ll knapsackBU2(int n, int mW) {
    // TC - O(nMW) SC - O(mW)
    std::vector<ll> dp_i_(mW+1, 0);
    std::vector<ll> dp_i_1(mW+1, 0);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= mW; j++) {
            dp_i_[j] = dp_i_1[j];
            if(wt[i] <= j) {
                dp_i_[j] = std::max(dp_i_[j], dp_i_1[j-wt[i]] + val[i]);
            }
        }
        dp_i_.swap(dp_i_1);
        dp_i_.clear();
    }
    return dp_i_1[mW];
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    std::memset(dp, -1, sizeof dp);

    std::cin>>n>>MW;
    val.pb(0);
    wt.pb(0);
    for(int i = 0; i < n; i++) {
        int value, w;
        std::cin>>value>>w;
        val.pb(value);
        wt.pb(w);
    }
    
    std::cout<<knapsack(n, MW)<<"\n";
    std::cout<<knapsackBU1(n, MW)<<"\n";
    std::cout<<knapsackBU2(n, MW)<<"\n";

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}