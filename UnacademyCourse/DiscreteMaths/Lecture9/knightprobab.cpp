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

int di[] = {2,2,1,1,-1,-1,-2,-2};
int dj[] = {1,-1,2,-2,2,-2,1,-1};
double dp[105][30][30];
double kptd(int n, int k, int i, int j) {
    if(i < 0 or j < 0 or  i >= n or j >= n) return 0;
    if(k == 0) return 1;
    if(dp[k][i][j] > -0.9) return dp[k][i][j];
    double ans = 0.0;
    for(int d = 0; d < 8; d++) {
        ans += kptd(n, k-1, i+di[d], j+dj[d])*(0.125);
    }
    return dp[k][i][j] = ans;
}

double kpbu(int n, int k, int i, int j) {
    std::vector<std::vector<double> > dp1(n, std::vector<double> (n, 0));
    dp1[i][j] = 1.0;
    for(; k > 0; k--) {
        std::vector<std::vector<double> > dp2(n, std::vector<double> (n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int d = 0; d < 8; d++) {
                    int ni = i+di[d];
                    int nj = j+dj[d];
                    if(ni >= 0 and  nj >= 0 and ni < n and nj < n) {
                        dp2[ni][nj] += dp1[i][j]*(0.125);
                    }
                }
            }
        }
        dp1 = dp2;
    }
    double ans = 0.0;
    for(auto &row : dp1) {
        for(int m = 0; m < n; m++) {
            ans += row[m];
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}