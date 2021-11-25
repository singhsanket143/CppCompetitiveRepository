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

struct node {
    ll sum;
    ll maxsum;
    ll bps;
    ll bss;
};

void build(vi &arr, std::vector<node*> &tree, ll s, ll e, ll ti) {
    if(s == e) {
        tree[ti]->maxsum = tree[ti]->sum = tree[ti]->bps = tree[ti]->bss = arr[s];
        return ;
    }

    ll m = mid(s, e);
    build(arr, tree, s, m, 2*ti);
    build(arr, tree, m+1, e, 2*ti+1);
    tree[ti]->sum = tree[2*ti]->sum + tree[2*ti+1]->sum;
    tree[ti]->bss = std::max(tree[2*ti+1]->sum + tree[2*ti]->bss, tree[2*ti+1]->bss);
    tree[ti]->bps = std::max(tree[2*ti]->sum + tree[2*ti+1]->bps, tree[2*ti]->bps);
    tree[ti]->maxsum = std::max({tree[2*ti]->maxsum, tree[2*ti+1]->maxsum, tree[2*ti]->sum + tree[2*ti+1]->bps, tree[2*ti+1]->sum + tree[2*ti]->bss, tree[2*ti]->bss+tree[2*ti+1]->bps});
}

node* query(std::vector<node*> &tree, ll s, ll e, ll ti, ll l, ll r) {
    node *temp = new node();
    temp->sum = temp->bps = temp->bss = temp->maxsum = INT_MIN;
    if(r < s or l > e) {
        return temp;
    }
    if(s >= l and e <= r) {
        return tree[ti];
    }
    ll m = mid(s, e);
    node *left = query(tree, s, m, 2*ti, l, r);
    node *right = query(tree, m+1, e, 2*ti+1, l, r);
    temp->sum = left->sum + right->sum;
    temp->bps = std::max(left->bps, left->sum+right->bps);
    temp->bss = std::max(right->bss, right->sum+left->bss);
    temp->maxsum = std::max({left->maxsum, right->maxsum, left->sum + right->bps, right->sum + left->bss, left->bss+right->bps});
    return temp;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n;
    std::cin>>n;
    vi arr(n);
    loop(i, 0, n-1) std::cin>>arr[i];
    std::vector<node*> tree(4*n);
    loop(i, 0, 4*n-1) tree[i] = new node();
    build(arr, tree, 0, n-1, 1);
    int q;
    std::cin>>q;
    while(q--) {
        int l , r;
        std::cin>>l>>r;
        std::cout<<query(tree, 0, n-1, 1, l-1, r-1)->maxsum<<"\n";
    }

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}