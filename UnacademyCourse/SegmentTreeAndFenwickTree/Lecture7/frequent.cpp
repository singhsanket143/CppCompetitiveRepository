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
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}

ll arr[100005];


struct node {
    ll ans; // most frequent element
    ll prefix_el;
    ll prefix_freq;
    ll suffix_el;
    ll suffix_freq;
    node(ll ans, ll prefix_el, ll prefix_freq, ll suffix_el, ll suffix_freq) {
        this->ans = ans;
        this->prefix_el = prefix_el;
        this->prefix_freq = prefix_freq;
        this->suffix_el = suffix_el;
        this->suffix_freq = suffix_freq;
    }

};

node* seg[400005];
node* merge(node *left, node *right) {
    node *result = new node(0,0,0,0,0);
    result->prefix_el = left->prefix_el;
    result->suffix_el = right->suffix_el;
    result->prefix_freq = left->prefix_freq;
    result->suffix_freq = right->suffix_freq;
    if(left->prefix_el == right->prefix_el) {
        result->prefix_freq += right->prefix_freq;
    }
    if(right->suffix_el == left->suffix_el) {
        result->suffix_freq += left->suffix_freq;
    }
    result->ans = std::max(left->ans, right->ans);
    if(left->suffix_el == right->prefix_el) {
        result->ans = std::max(result->ans, left->suffix_freq + right->prefix_freq);
    }
    return result;
}

void build(ll l, ll r, ll ti) {
    if(l > r) return;
    if(l == r) {
        seg[ti] = new node(1, arr[l], 1, arr[r], 1);
        //log(l, r, ti, seg[ti]->ans, seg[ti]->prefix_el, seg[ti]->prefix_freq, seg[ti]->suffix_el, seg[ti]->suffix_freq);

        return;
    }
    ll m = (l+r) / 2;
    build(l, m, 2*ti+1);
    build(m+1, r, 2*ti+2);
    seg[ti] = merge(seg[2*ti+1], seg[2*ti+2]);
    //log(l, r, ti, seg[ti]->ans, seg[ti]->prefix_el, seg[ti]->prefix_freq, seg[ti]->suffix_el, seg[ti]->suffix_freq);
}

node* query(ll l, ll r, ll ns, ll ne, ll ti) {
    if(ns > ne or ns > r or ne < l) return new node(0,0,0,0,0);
    if(ns >= l and ne <= r) return seg[ti];
    ll m = (ns + ne) / 2;
    // log(l, r, ns, ne, ti, m);

    node *left = query(l, r, ns, m, 2*ti+1);
    node *right = query(l, r, m+1, ne, 2*ti+2);
    return merge(left, right);
    // return new node(0,0,0,0,0);
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    ll n, q;
    // scanf("%lld", &n);
    std::cin>>n;
    while(n) {
        // scanf("%lld", &q);
        std::cin>>q;
        for(int i = 0 ; i < n; i++) {
            // scanf("%lld", &arr[i]);
            std::cin>>arr[i];
        }
        // for(int i = 0; i < n; i++) std::cout<<arr[i]<<" ";
        // std::cout<<"\n";
        // for(int i = 0 ; i < 400005; i++) {
        //     seg[i] = new node(0,0,0,0,0);
        // }
        build(0, n-1, 0);
        // std::cout<<seg[0]->ans;
        
        while(q--) {
            ll l, r;
            // scanf("%lld %lld", &l, &r);
            std::cin>>l>>r;

            l--; r--;
            // std::cout<<l<<" "<<r<<"\n";
            node *result = query(l, r, 0, n-1, 0);
            printf("%lld\n",result->ans);
        }
        // scanf("%lld", &n);
        std::cin>>n;
    }

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}