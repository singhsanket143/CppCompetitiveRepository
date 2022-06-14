// Problem Link - https://atcoder.jp/contests/dp/tasks/dp_n
/* By Sanket Singh */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << endl;
    err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

std::vi arr;
ll sum[405][405];
ll dp[405][405];
ll f(int i, int j) {
    /*
    TIME: O(N^3)
    SPACE: O(N^2)
    */
    if(i == j) {
        return 0; // cost of combining single slime to itself
    }
    if(dp[i][j] != -1) return dp[i][j];
    ll ans = inf;
    // log(i, j);
    for(int k = i; k <= j-1; k++) {
        // log(k);
        ans = min(ans, f(i, k) + f(k+1, j) + sum[i][j]);
    }
    // log(ans);
    return dp[i][j] = ans;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n;
    std::cin>>n;
    arr.resize(n+1, 0);
    loop(i, 1, n) {
        std::cin>>arr[i];
    }
    // logarr(arr, 0, arr.size() - 1);
    memset(sum, 0, sizeof sum);
    memset(dp, 0, sizeof dp); // for bottom up initialise by 0 otherwise by -1

    // sum[i][j] = a[i] + a[i+1] + a[i+2] .... a[j-1] + a[j];
    loop(i, 1, n) {
        loop(j, i, n) {
            sum[i][j] = arr[j] + ((i == j) ? 0 : sum[i][j-1]);
        }
    }
    // std::cout<<f(1, n);
    for(int len = 2; len <= n; len++) {
        for(int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = inf;
            for(int k = i; k <= j-1; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum[i][j]);
            }
        }
    }
    
    std::cout<<dp[1][n];

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}