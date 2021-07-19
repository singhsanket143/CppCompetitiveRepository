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
    
}


class Counter {
protected:
    int count;
public:
    Counter() : count(0) {
        std::cout<<"Base class constructor 1 called\n";
    };
    Counter(int c) : count(c) {
        std::cout<<"Base class constructor 2 called\n";
    }
    int get_count() const {
        return this->count;
    }

    int get_count() {
        return this->count;
    }
    Counter operator ++ () {
        return Counter(this->count++);
    }
    ~Counter() {
        std::cout<<"Base class Destructor called\n";
    }
};

class CountDn : public Counter {
public:
    
    CountDn() {
        std::cout<<"Derived class constructor 1 called\n";
    }

    CountDn(int c) : Counter(c) {
        std::cout<<"Derived class constructor 2 called\n";
    } 
    Counter operator --() {
        return Counter(--this->count);
    }
    ~CountDn() {
        std::cout<<"Derived class Destructor called\n";
    }
};

class CountDnInherit : public CountDn {
public:
    void operator --() {
        --this->count;
    }
};

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    CountDn c1;
    // log(c1.get_count());
    // ++c1; ++c1;
    // log(c1.get_count());

    CountDn c2(2);

    CountDnInherit c3;
    // c3.get_count();

    
    return 0;
}