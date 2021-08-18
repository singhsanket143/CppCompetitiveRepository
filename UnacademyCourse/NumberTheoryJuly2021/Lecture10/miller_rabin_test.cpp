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

// a*7 = 4a+2a+a

ll modular_multi(ll a, ll b, ll n) {
    ll result = 0;
    while(b) {
        if(b%2 != 0) result += a;
        a *= 2;
        b /= 2;
        result %= n;
        a %= n;
    }
    return result;
}

ll modular_expo(ll a, ll b, ll n) {
    ll res = 1;
    while(b) {
        if(b%2!=0) {
            res = modular_multi(res, a, n);
            
        }
        a = modular_multi(a, a, n);
        a%=n;
        b/=2;
    }
    return res;
}

bool miller_rabin(ll n) {

    if(n == 1) return false;
    if(n == 2) return true;
    if(n%2 == 0) return false;
    // we can say for sure that n is odd then n-1 is even
    ll d = n - 1, s = 0;
    while(d%2 == 0) {
        d/=2;
        s++;
    }
    // (n-1) = d*(2^s)
    // d is an odd number
    std::vector<ll> a {2,3,5,7,11,13,17,19,23};
    for(int i = 0; i < a.size(); i++) {
        if(a[i] > n-2) continue;
        ll res = modular_expo(a[i], d, n);
        if(res%n == 1) continue;
        bool prime = false;
        for(int r = 0; r <= s-1; r++) {
            ll ans = modular_expo(2, r, n);
            ll finalans = modular_expo(res, ans, n);
            if(finalans%n == n-1 or finalans%n == 1) {
                prime = true;
                break;
            }
        }
        if(not prime) return false;
    }
    return true;
}
int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int t;
    std::cin>>t;
    while(t--) {
    int n;
        std::cin>>n;

        if(miller_rabin(n)) {
            std::cout<<"prime\n";
        } else {
            std::cout<<"Not prime\n";
        }
    }
    

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}