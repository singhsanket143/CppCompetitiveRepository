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

struct node {
    int data;
    node *left;
    node *right;
    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* build() {
    // return the head of the tree.
    int d;
    std::cin>>d;
    if(d == -1) return NULL;
    node* root = new node(d);
    root->left = build();
    root->right = build();
    return root;
}

void preorder(node *root) {
    if(root == NULL) return;
    std::cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    std::cout<<root->data<<" ";
}

void inordered(node *root) {
    if(root == NULL) return;
    inordered(root->left);
    std::cout<<root->data<<" ";
    inordered(root->right);
}
int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    node *root = build();
    preorder(root);
    std::cout<<"\n";
    postorder(root);
    std::cout<<"\n";
    inordered(root);
    std::cout<<"\n";

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}

// 1 2 4 -1 -1 5 -1 8 -1 -1 3 6 -1 9 -1 -1 7 -1 -1