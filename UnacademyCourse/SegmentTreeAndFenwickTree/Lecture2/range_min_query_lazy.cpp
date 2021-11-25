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

vi arr; // storing the elemtns
vi tree; // array fo segtree
vi lazy; // for lazy storage

ll query(int nl, int nr, int ti, int l, int r) {
   if(lazy[ti] != 0) {
        // you have a loan
        tree[ti] += lazy[ti];
        if(nl != nr) {
            lazy[2*ti+1] += lazy[ti];
            lazy[2*ti+2] += lazy[ti];
        }
        lazy[ti] = 0;
    }
    if(l > nr or r < nl) {
        return INT_MAX;
    }
    if(l <= nl and r >= nr) {
        return tree[ti];
    }
    int m = nl + (nr-nl)/2;
    ll left = query(nl, m, 2*ti+1, l, r);
    ll right = query(m+1, nr, 2*ti+2, l, r);
    return std::min(left, right);
}

void update(int nl, int nr, int ti, int l, int r, int val) {
    if(lazy[ti] != 0) {
        // you have a loan
        tree[ti] += lazy[ti];
        if(nl != nr) {
            lazy[2*ti+1] += lazy[ti];
            lazy[2*ti+2] += lazy[ti];
        }
        lazy[ti] = 0;
    }

    if(l > nr or r < nl) {
        return;
    }
    if(l <= nl and r >= nr) {
        // complete overlap
        tree[ti] += val;
        if(nl != nr) {
            lazy[2*ti+1] += val;
            lazy[2*ti+2] += val;
        }
        return;
    }
    int m = nl + (nr-nl)/2;
    update(nl, m, 2*ti+1, l, r, val);
    update(m+1, r, 2*ti+2, l, r, val);
    tree[ti] = std::min(tree[2*ti+1], tree[2*ti+2]);
}

void buildTree(int nl, int nr, int ti) { // ti -> segment tree index
    if(nl == nr) {
        tree[ti] = arr[nl];
        return;
    }
    int m = nl + (nr-nl)/2;
    buildTree(nl, m, 2*ti+1);
    buildTree(m+1, nr, 2*ti+2);
    tree[ti] = std::min(tree[2*ti+1], tree[2*ti+2]);
}


int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n;
    std::cin>>n;
    arr.resize(n);
    tree.resize(4*n, 0);
    lazy.resize(4*n, 0);
    loop(i, 0, n-1) std::cin>>arr[i];
    buildTree(0, n-1, 0);
    int q;
    std::cin>>q;
    while(q--) {
        int type;
        std::cin>>type;
        if(type == 0) {
            // update
            int l, r, val;
            std::cin>>l>>r>>val;
            update(0, n-1, 0, l, r, val);
        } else {
            int l, r;
            std::cin>>l>>r;
            std::cout<<query(0, n-1, 0, l, r)<<"\n";
        }
        
    }

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}