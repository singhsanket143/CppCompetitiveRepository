// Problem Link - https://www.hackerearth.com/problem/algorithm/recurrence/
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

int k = 2;
std::vector<std::vector<ll> > multiply(std::vector<std::vector<ll> > &a, std::vector<std::vector<ll> > &b) {
    ll MOD = mod-1;
    std::vector<std::vector<ll> > c(k, std::vector<ll> (k, 0) );
    c[0][0] = (((a[0][0]%MOD)*(b[0][0]%MOD))%MOD + ((a[0][1]%MOD)*(b[1][0]%MOD))%MOD)%MOD;
    c[0][1] = (((a[0][0]%MOD)*(b[1][0]%MOD))%MOD + ((a[0][1]%MOD)*(b[1][1]%MOD))%MOD)%MOD;
    c[1][0] = (((a[1][0]%MOD)*(b[0][0]%MOD))%MOD + ((a[1][1]%MOD)*(b[1][0]%MOD))%MOD)%MOD;
    c[1][1] = (((a[1][0]%MOD)*(b[0][1]%MOD))%MOD + ((a[1][1]%MOD)*(b[1][1]%MOD))%MOD)%MOD;

    return c;
}

void power(std::vector<std::vector<ll> > &a, int n) {
    if(n == 0 or n == 1) return;
    power(a, n/2);
    a = multiply(a, a);
    if((n%2)!=0) {
        std::vector<std::vector<ll> > m {{0,1}, {1,1}};
        a = multiply(a, m);
    }
}

ll fib(int n, int x, int y) {
    ll MOD = mod-1;
    std::vector<std::vector<ll> > a {{0,1}, {1,1}};
    if(n == 0) return 0;
    power(a, n-1);
    ll f1[2] = {0, 1};
    return ((a[1][0]%MOD*f1[0]%MOD)%MOD + (a[1][1]%MOD*f1[1]%MOD)%MOD)%MOD;
}


ll binary_expo_iter(ll a, ll b) {
    ll res = 1;
    a%=mod;
    while(b > 0) {
        if(b%2 != 0) {
            res = ((res%mod)*(a%mod))%mod;
        }
        a = ((a%mod)*(a%mod))%mod;
        b >>= 1;
    }
    return res;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int t;
    // log(fib(10000007, 0, 1));
    scanf("%d", &t);
    while(t--) {
        ll f0, f1, n;
        scanf("%lld %lld %lld", &f0, &f1, &n);
        if(n == 0) {
            printf("%lld\n", f0);
        } else if(n==1) {
            printf("%lld\n", f1);
        } else {
            ll x = fib(n-1, f0, f1) % (mod-1);
            ll y = fib(n, f0, f1) % (mod-1);
            // log(x, y);
            ll result = ((binary_expo_iter(f0+1, x)%mod) * (binary_expo_iter(f1 + 1, y)%mod))%mod;
            // log(result)
            printf("%lld\n", (result-1)%mod);
        }
    }

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}