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
std::unordered_map<char, int> m;
std::unordered_map<char, std::string> codes;

struct node {
public:
    pii data;
    node* left;
    node* right;
    bool code;
    int sz;
    node(char ch, int data = 0) {
        this->data = {ch, data};
        this->left = NULL;
        this->right = NULL;
        sz = 1;
    }
};

class cmp {
public:
    int operator () (const node *o1, const node *o2) {
        if(o1->data.ss == o2->data.ss) {
            return o1->data.ff > o2->data.ff;
        }
        return o1->data.ss > o2->data.ss;
    }
};

void assign_code(node *&root) {
    if(root == NULL) return;
    std::cout<<(char)root->data.ff<<" "<<root->data.ss<<"\n";
    if(root->left != NULL) {
        std::cout<<"Left\n";
        root->left->code = 0;
        assign_code(root->left);
    }
    if(root->right != NULL) {
        std::cout<<"right\n";
        root->right->code = 1;
        assign_code(root->right);
    }
}

void read_tree(node *&root, std::string csf) {
    if(root == NULL) return;
    if(root->left == NULL and root->right == NULL) {
        codes[root->data.ff] = csf;
        return;
    }
    if(root->left != NULL) {
        read_tree(root->left, csf + '0');
    }
    if(root->right != NULL) {
        read_tree(root->right, csf + '1');
    }
}

void huffman_encode(std::string &str) {
    for(int i = 0; i < str.size(); i++) {
        m[str[i]]++;
    }
    std::priority_queue<node*,std::vector<node*>,cmp > pq;

    for(auto &p : m) {
        char ch = p.ff;
        node* new_node = new node(p.ff, p.ss);
        pq.push(new_node);
    }

    while(pq.size() > 1) {
        node* el1 = pq.top();
        pq.pop();
        node* el2 = pq.top();
        pq.pop();
        log((char)el1->data.ff, el1->data.ss, (char)el2->data.ff, el2->data.ss);
        node* temp = new node(' ', el1->data.ss + el2->data.ss);
        if(el1->sz < el2->sz) {
            temp->left = el1;
            temp->right = el2;
        } else if(el1->sz == el2->sz) {
            if(el1->data.ff != ' ') {
                temp->left = el1;
                temp->right = el2;
            } else {
                temp->left = el2;
                temp->right = el1;
            }
        }
        else {
            temp->left = el2;
            temp->right = el1;
        }
        
        temp->sz += (temp->left->sz + temp->right->sz);
        log(el1, el2, temp);
        pq.push(temp);
    }
    node* final_tree = pq.top();
    assign_code(final_tree);
    read_tree(final_tree, "");
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    std::string str = "";
    // std::cin>>str;
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    for(int i =0 ; i < 6; i++) {
        for(int j = 0; j < freq[i]; j++) {
            str += arr[i];
        }
    }
    std::cout<<str<<"\n";
    huffman_encode(str);
    for(auto &p : codes) {
        std::cout<<p.ff<<" "<<p.ss<<"\n";
    }

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}