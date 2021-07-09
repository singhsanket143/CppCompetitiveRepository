// Problem Link - https://www.spoj.com/problems/SUBXOR/
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

class TrieNode {
public:
    TrieNode *next[2];
    int count;
    TrieNode() {
        next[0] = next[1] = NULL;
        count = 0;
    }
};

void insert(TrieNode *root, ll num) {
    TrieNode *curr = root;
    for(int i = 31; i >= 0; i--) {
        int bit = (num >> i)&1;
        if(not curr->next[bit]) {
            curr->next[bit] = new TrieNode();
        }
        curr = curr->next[bit];
        curr->count++;
    }
}

ll query(TrieNode *root, int k, ll pre) {
    TrieNode *curr = root;
    int result = 0;
    for(int i = 31; i>= 0; i--) {
        if(curr == NULL) break;
        int q = (k >> i)&1;
        int p = (pre >> i)&1;
        if(p == q) {
            if(q == 1) {
                result += ((curr->next[1] != NULL) ? curr->next[1]->count : 0);
            }
            curr = curr->next[0]; //go left
        } else {
            if(q == 1) {
                result += ((curr->next[0] != NULL) ? curr->next[0]->count : 0);
            }
            curr = curr->next[1]; // go right
        }
    }
    return result;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int t;
    std::cin>>t;
    while(t--) {
        int n, k;
        std::cin>>n>>k;
        TrieNode* root = new TrieNode();
        insert(root, 0);
        ll pre = 0;
        ll ans = 0;
        while(n--) {
            ll num;
            std::cin>>num;
            pre = pre^num;
            ans += query(root, k, pre);
            insert(root, pre);
        }
        std::cout<<ans<<"\n";
    }

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}