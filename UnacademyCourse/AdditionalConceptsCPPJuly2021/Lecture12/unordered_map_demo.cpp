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


struct hash_pair {
    template<class T1, class T2>
    size_t operator () (const std::pair<T1, T2> &p) const {
        auto h1 = std::hash<T1>()(p.first);
        auto h2 = std::hash<T2>()(p.second);
        return ((h1^h2)*(h1+h2))%mod;
    }
};

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    std::unordered_map<char, int> m1;
    m1.insert({'a', 1});
    m1['b'] = 2;
    m1.insert(std::make_pair('c', 3));
    for(auto &p: m1) {
        std::cout<<p.first<<" "<<p.second<<"\n";
    }

    std::unordered_map<int, int> m2 ({{3,4}, {2,3}, {0, 9}});
    for(auto &p: m2) {
        std::cout<<p.first<<" "<<p.second<<"\n";
    }

    std::unordered_map<std::pair<int, int>, int, hash_pair > m3;
    std::unordered_map<std::string, int > m4;
    std::unordered_map<std::string, int >::iterator it;
    std::pair<std::pair<int, int> , int> p1;

    if(m2.count(12)) {
        std::cout<<"present\n";
    } else {
        std::cout<<"Absent\n";
    }

    if(m2.find(12) != m2.end()) {
        std::cout<<"Present\n";
    } else {
        std::cout<<"Absent\n";
    }

    for(auto &p : m2) {
        if(p.first < 1) {
            m2.erase(p.first);
        }
    }

    for(auto i = m2.begin(); i != m2.end(); i++) {
        if(i->second == 3) {
            m2.erase(i);
        }
    }

    for(auto &p: m2) {
        std::cout<<p.first<<" "<<p.second<<"\n";
    }

    m2.emplace(4,5);

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}