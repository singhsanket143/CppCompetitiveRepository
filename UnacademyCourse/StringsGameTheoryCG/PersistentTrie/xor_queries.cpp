// Problem Link - https://www.codechef.com/problems/XRQRS
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
    // 
}

const int N = 500005*22;

struct node {
    int left, right, count;
};

node trie[N];
int root[N];
int new_ptr; // last available location

int insert(int prev, int x) {
    int temp = new_ptr++;
    int curr = temp;
    trie[curr] = trie[prev]; // copy of root

    for(int i = 20; i>= 0; i--) {
        int b = (x>>i)&1;
        if(b) {
            trie[curr].right = new_ptr++;
            trie[trie[curr].right] = trie[trie[prev].right];
            trie[trie[curr].right].count++;
            curr = trie[curr].right;
            prev = trie[prev].right;
        } else {
            trie[curr].left = new_ptr++;
            trie[trie[curr].left] = trie[trie[prev].left];
            trie[trie[curr].left].count++;
            curr = trie[curr].left;
            prev = trie[prev].left;
        }
    }
    return temp;
}

int max_xor(int prev, int curr, int x) {
    int y = 0 ;
    for(int i = 20; i >= 0; i--) {
        int b = (x >>i)&1;
        if(b) {
            if(trie[trie[curr].left].count > trie[trie[prev].left].count) {
                curr = trie[curr].left;
                prev = trie[prev].left;
            } else {
                curr = trie[curr].right;
                prev = trie[prev].right;
                y += (1 << i);
            }
        } else {
            if(trie[trie[curr].right].count > trie[trie[prev].right].count) {
                curr = trie[curr].right;
                prev = trie[prev].right;
                y += (1 << i);
            } else {
                curr = trie[curr].left;
                prev = trie[prev].left;
            }
        }
    }
    return y;
}

int less_than_equal_to(int prev, int curr, int x) {
    int ans = 0;
    for(int i = 20; i >= 0; i--) {
        int b = (x>>i)&1;
        if(b) {
            ans += trie[trie[curr].left].count - trie[trie[prev].left].count;
            curr = trie[curr].right;
            prev = trie[prev].right;
        } else {
            curr = trie[curr].left;
            prev = trie[prev].left;
        }
    }
    ans += trie[curr].count - trie[prev].count;
    return ans;
}

int kth_smallest(int prev, int curr, int k) {
    int ans = 0;
    for(int i = 20; i >= 0; i--) {
        if(trie[trie[curr].left].count - trie[trie[prev].left].count >= k) {
            curr = trie[curr].left;
            prev = trie[prev].left;
        } else {
            k -= (trie[trie[curr].left].count - trie[trie[prev].left].count);
            ans += (1 << i);
            curr = trie[curr].right;
            prev = trie[prev].right;
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    root[0] = 0;
    trie[0].left = trie[0].right = trie[0].count = 0;
    new_ptr = 1;
    int n = 1; // entries
    int m;
    std::cin>>m;
    while(m--) {
        int type;
        std::cin>>type;
        if(type == 0) {
            // insertion
            int x;
            std::cin>>x;
            root[n] = insert(root[n-1], x);
            n+=1;
        } else if(type == 1) {
            int l, r, x;
            std::cin>>l>>r>>x;
            std::cout<<max_xor(root[l-1], root[r], x)<<"\n";
        } else if(type == 2) {
            int k;
            std::cin>>k;
            n-=k;
        } else if(type == 3) {
            int l, r, x;
            std::cin>>l>>r>>x;
            std::cout<<less_than_equal_to(root[l-1], root[r], x)<<"\n";
        } else if(type == 4) {
            int l, r, k;
            std::cin>>l>>r>>k;
            std::cout<<kth_smallest(root[l-1], root[r], k)<<"\n";
        }
    }

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}