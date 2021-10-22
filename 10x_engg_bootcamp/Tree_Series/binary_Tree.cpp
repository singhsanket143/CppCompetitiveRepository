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
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}

struct node {
    int data;
    node *left;
    node *right;
    node *next;
    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
        next = NULL;
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

void preorder_iterative(node* root) {
    if(root == NULL) return;
    std::stack<node*> st;
    st.push(root); // this is the first node to be processed

    while(not st.empty()) {
        std::cout<<st.top()->data<<" ";
        node* curr = st.top();
        st.pop();

        if(curr->right) {
            st.push(curr->right);
        }
        if(curr->left) {
            st.push(curr->left);
        }
    }
    return;
}

void level_order(node* root) {
    if(root == NULL) return;
    std::queue<node*> qu;
    qu.push(root);
    while(not qu.empty()) {
        node* curr = qu.front();
        std::cout<<curr->data<<" ";
        qu.pop();
        if(curr->left) {
            qu.push(curr->left);
        }
        if(curr->right) {
            qu.push(curr->right);
        }
    }

}


void level_order_levelwise(node* root) {
    if(root == NULL) return;
    std::queue<node*> qu;
    qu.push(root);
    qu.push(NULL);
    while(not qu.empty()) {
        if(qu.front() == NULL) {
            std::cout<<"\n";
            qu.pop();
            if(qu.size() == 0) break;
            qu.push(NULL);
            continue;
        }
        node* curr = qu.front();
        std::cout<<curr->data<<" ";
        qu.pop();
        if(curr->left) {
            qu.push(curr->left);
        }
        if(curr->right) {
            qu.push(curr->right);
        }
    }

}
int max_level = INT_MIN;
void right_view(node* root, int curr_level) {
    if(root == NULL) return;
    if(max_level < curr_level) {
        std::cout<<root->data<<" ";
        max_level = curr_level;
    }
    right_view(root->right, curr_level+1);
    right_view(root->left, curr_level+1);
}

int height(node* root) {
    if(root == NULL) return 0;
    if(root->left == NULL and root->right == NULL) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return std::max(lh, rh) + 1;
}



int diameter(node* root) {
    if(root == NULL) return 0;
    if(root->left == NULL and root->right == NULL) return 0;
    int left = diameter(root->left);
    int right = diameter(root->right);

    int lh = height(root->left);
    int rh = height(root->right);
    int via_root = lh + rh + (root->left != NULL) + (root->right != NULL);

    return std::max({left, right, via_root});
}


std::pair<int, int> diameter_btr(node* root) { // first -> diameter, second -> height
    if((root == NULL) or (root->left == NULL and root->right == NULL)) {
        std::pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    std::pair<int, int> left = diameter_btr(root->left);
    std::pair<int, int> right = diameter_btr(root->right);

    int h = std::max(left.second, right.second) + 1;
    int d = std::max({left.first, right.first, left.second + right.second + 2});

    return {d, h};
}
node* lca_ans = NULL;
bool lca(node* root, node* n1, node* n2) {
    if(root == NULL) return false;

    int left = lca(root->left, n1, n2) ? 1 : 0;
    int right = lca(root->right, n1, n2) ? 1 : 0;

    int curr = (root->data == n1->data or root->data == n2->data);
    if(curr + left + right >= 2) {
        lca_ans = root;
    }
    return (curr + left + right) > 0;
}



node* leftmost;
node* prev;

void process(node* child) {
    if(child == NULL) return;
    if(prev != NULL) {
        prev->next = child;
    } else {
        leftmost = child;
    }p
    prev = child;
}

node* populate(node *root) {
    if(root == NULL) return root;
    leftmost = root;
    node *curr = leftmost;
    while(leftmost != NULL) {
        prev = NULL;
        curr = leftmost;
        leftmost = NULL;
        while(curr != NULL) {
            process(curr->left);
            process(curr->right);
        }
    }
    return root;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    node *root = build();
    preorder(root);
    std::cout<<"\n";
    // postorder(root);
    // std::cout<<"\n";
    // inordered(root);
    // std::cout<<"\n";
    preorder_iterative(root);
    std::cout<<"\n";
    level_order(root);
    std::cout<<"\n";
    level_order_levelwise(root);
    std::cout<<"\n";
    right_view(root, 0);
    std::cout<<"\n";
    std::cout<<diameter(root)<<"\n";
    std::pair<int, int> p = diameter_btr(root);
    std::cout<<p.first<<"\n";
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}

// 1 2 -1 4 -1 7 -1 -1 3 5 -1 8 -1 10 -1 12 -1 -1 6 -1 9 -1 11 -1 13 -1 14 -1 -1 