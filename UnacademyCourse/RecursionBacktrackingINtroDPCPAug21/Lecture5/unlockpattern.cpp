// Problem Link - https://leetcode.com/problems/android-unlock-patterns/
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

int via[10][10];

int helper(std::vector<bool> &visited, int curr, int remaining, std::string out) {
    if(remaining < 0) return 0;
    if(remaining == 0) {
        std::cout<<out<<"\n";
        return 1;
    }
    visited[curr] = true;
    int result = 0;
    for(int i = 1; i <= 9; i++) {
        if(not visited[i] and (via[curr][i] == 0 or visited[via[curr][i]])) {
            result += helper(visited, i, remaining-1, out + std::to_string(i));
        }
    }
    visited[curr] = false;
    return result;

}

int numberOfPatterns(int m, int n) {
    std::memset(via, 0, sizeof via);
    via[1][3] = via[3][1] = 2;
    via[1][7] = via[7][1] = 4;
    via[7][9] = via[9][7] = 8;
    via[3][9] = via[9][3] = 6;
    via[1][9] = via[9][1] = via[3][7] = via[7][3] = via[2][8] = via[8][2] = via[4][6] = via[6][4] = 5;

    std::vector<bool> visited(10, false);
    int ways = 0;
    for(int i = m; i <= n; i++) {
        // ways += helper(visited, 1, i-1, "1")*4; // 1, 3, 7, 9, symmetry
        // ways += helper(visited, 2, i-1, "2")*4; // 2, 4, 8, 6, symmetry
        // ways += helper(visited, 5, i-1, "5"); // 5
        for(int j = 1; j <= 9; j++) {
            ways += helper(visited, j, i-1, ""+std::to_string(j));
        }
    }

    return ways;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    std::cout<<numberOfPatterns(1,2)<<"\n";

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}