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

int ways = 0;

bool isSafe(std::vector<std::vector<bool > > &board, int row, int col) {
    int n = board.size();
    for(int i = row - 1; i >= 0; i--) {
        if(board[i][col]) return false;
    }
    // left diag
    for(int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--) {
        if(board[i][j]) return false;
    }
    // right diag
    for(int i = row - 1, j = col + 1; i >= 0 and j < n ; i--, j++) {
        if(board[i][j]) return false;
    }
    return true;
}

void display(std::vector<std::vector<bool > > &board) {
    for(auto &row : board) {
        for(int i = 0 ; i <row.size(); i++) {
            bool el = row[i];
            if(!el) {
                std::cout<<".";
            } else {
                std::cout<<"Q";
            }
        }
        std::cout<<"\n";
    }
}

void nqueen(int n, int i, std::vector<std::vector<bool > > &board) {
    if(i == n) {
        display(board);
        std::cout<<"-----------------\n";
        ways++;
        return;
    }
    for(int j = 0; j < n; j++) {
        if(isSafe(board, i, j)) {
            board[i][j] = true;
            nqueen(n, i+1, board);
            board[i][j] = false;
        }
    }
}

std::bitset<30> col, lt, rt;
void nqueenop(int n, int i, std::vector<std::vector<bool > > &board) {
    if(i == n) {
        display(board);
        std::cout<<"-----------------\n";
        ways++;
        return;
    }
    for(int j = 0; j < n; j++) {
        if(col[j] == 0 and lt[i-j+n-1] == 0 and rt[i+j] == 0) {
            col[j] = lt[i-j+n-1] = rt[i+j] = 1;
            board[i][j] = true;
            nqueenop(n, i+1, board);
            board[i][j] = false;
            col[j] = lt[i-j+n-1] = rt[i+j] = 0;
        }
    }
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n;
    std::cin>>n;
    std::vector<std::vector<bool > > board(n, std::vector<bool> (n, false));
    // nqueen(n, 0, board);
    col.reset();
    lt.reset();
    rt.reset();
    // std::cout<<col<<"\n";
    nqueenop(n, 0, board);
    log(ways);
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}