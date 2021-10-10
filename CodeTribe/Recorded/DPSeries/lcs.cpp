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

std::string s1;
std::string s2;
int dp[1005][1005];

int lcs(int i, int j) { // top down dp implementations
    // base case
    if(i < 0 or j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]) return dp[i][j] = 1 + lcs(i-1, j-1);
    else {
        return dp[i][j] = std::max(lcs(i-1, j), lcs(i, j-1));
    }
}

int lcsBU1() {
    int n = s1.size();
    int m = s2.size();
    std::vector<std::vector<int> > dp(n+1, std::vector<int> (m+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int lcsBU2() {
    int n = s1.size();
    int m = s2.size();
    std::vector<int> dp1(m+1, 0);
    std::vector<int> dp2(m+1, 0);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp2[j] = 1 + dp1[j];
            } else {
                dp2[j] = std::max(dp1[j], dp2[j-1]);
            }
        }
        dp1.swap(dp2);
        dp2.clear();
    }
    return dp1[m];
}

std::string printLCS() {
    int n = s1.size();
    int m = s2.size();
    std::vector<std::vector<int> > dp(n+1, std::vector<int> (m+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i = n, j = m;
    std::string result = "";
    while(i > 0 and j > 0) {
        if(s1[i-1] == s2[j-1]) {
            result += s1[i-1];
            i--;
            j--;
        } else {
            if(dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    s1 = "axyb";
    s2 = "abyxb";
    std::memset(dp, -1, sizeof dp);
    log(lcs(s1.size() - 1, s2.size() - 1));
    log(lcsBU1());
    log(lcsBU2());
    log(printLCS());

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}