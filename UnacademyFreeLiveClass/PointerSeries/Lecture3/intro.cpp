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

struct temp {
    int x;
    temp() {
        std::cout<<"Constructor called\n";
    }
    ~temp() {
        std::cout<<"Destructor Called\n";
    }
};

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    // std::unique_ptr<int> ptr1(new int(101));
    // std::cout<<*ptr1<<"\n";

    // // std::unique_ptr<int> ptr2 = ptr1;
    // std::unique_ptr<int> p1 = std::make_unique<int> (1001);
    // std::cout<<*p1<<"\n";

    // int *p1 = new int(101);
    // int *p2 = p1;
    // std::cout<<*p1<<" "<<*p2<<"\n";

    {
        // temp* t1 = new temp();
        // delete t1;  
        std::unique_ptr<temp> t1(new temp());

    }
    // delete t1;
    // delete t1;

    // std::unique_ptr<temp> t1(new temp());

    std::shared_ptr<temp> t2(new temp());
    std::shared_ptr<temp> t3 = t2;
    {
        std::shared_ptr<temp> t4 = t2;
        std::cout<<t2.use_count()<<"\n"; // reference count
    }

    std::cout<<t2.use_count()<<"\n";

    {
        std::shared_ptr<temp> t4(new temp());
        std::shared_ptr<temp> t5 = t4;
    }
    std::cout<<"t3 = "<<t3<<"\n";
    t3.reset();
    std::cout<<"t3 = "<<t3<<"\n";
    std::cout<<"t2 = "<<t2<<"\n";
    t2.reset();
    std::cout<<"t2 = "<<t2<<"\n";
    std::cout<<t2.use_count()<<"\n";


    std::shared_ptr<int> s = std::make_shared<int>(75);
    std::cout<<*s<<"\n";

    // int *x = s; // this will throw error
    std::shared_ptr<int> p = std::make_shared<int>(99); // 12k
    std::shared_ptr<int> p1 = p; // 12k

    std::weak_ptr<int> w = p;
    std::cout<<"use count = "<<p.use_count()<<"\n";
    // std::cout<<*w<<"\n"; // weak pointers cant be dereferenced
    std::cout<<"value of w = "<<w.expired()<<"\n";
    p.reset();
    std::cout<<"value of w = "<<w.expired()<<"\n";
    p1.reset();
    std::cout<<"value of w = "<<w.expired()<<"\n"; // like a watcher



    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}