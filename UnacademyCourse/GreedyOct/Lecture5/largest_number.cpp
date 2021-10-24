// Problem Link - https://leetcode.com/problems/largest-number/
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
bool cmp(std::string &s1, std::string &s2) {
        return (s1+s2) > (s2+s1);
}
class Solution {
public:
    
    std::string largestNumber(std::vector<int>& nums) {
        std::vector<std::string> arr;
        for(int i = 0; i < nums.size(); i++) {
            arr.emplace_back(std::to_string(nums[i]));
        }
        std::sort(arr.begin(), arr.end(), cmp);
        if(arr[0] == "0") { // ["0","0","0"] => "0"
            return "0";
        }
        std::string result = "";
        for(auto &str : arr) {
            result += str;
        }
        return result;
    }
};
int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}

/*
Theorem:

Let a, b, and c be non-negative integers. If a.b > b.a and b.c > c.b , we have a.c > c.a .

Proof:

We use [a] to denote the length of the decimal representation of a . For example, if a = 10 , we have [a] = 2 .

Since a.b > b.a and b.c > c.b , we have

a * 10^[b] + b > b * 10^[a] + a
b * 10^[c] + c > c * 10^[b] + b

, which is equivalent to

a * (10^[b] - 1) > b * (10^[a] - 1)
b * (10^[c] - 1) > c * (10^[b] - 1)

Obviously, 10^[a] - 1 > 0 , 10^[b] - 1 > 0 , and 10^[c] - 1 > 0 . Since c >= 0 , according to the above inequalities, we know that b > 0 and a > 0 . After multiplying the above two inequalities and cancelling b and (10^[b] - 1) , we have

a * (10^[c] - 1) > c * (10^[a] - 1)

This is equivalent to

a * 10^[c] + c > c * 10^[a] + a

, which means a.c > c.a .

Q.E.D.
*/