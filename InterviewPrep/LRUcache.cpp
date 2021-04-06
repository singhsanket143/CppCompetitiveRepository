// Problem Link - 
/* By Sanket Singh */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
class DLLNode {
public:
	int key;
	int value;
	DLLNode *prev;
	DLLNode *next;
	DLLNode(int key, int value) {
		this->key = key;
		this->value = value;
		this->prev = NULL;
		this->next = NULL;
	}
};


unordered_map<int, DLLNode*> cache;
int size;
int capacity = 0;
DLLNode* head = new DLLNode(-1, -1);
DLLNode* tail = new DLLNode(-1, -1);



void addNodeatHead(DLLNode *node) {
	node->prev = head;
	node->next = head->next;
	head->next->prev = node;
	head->next = node;
	return;
}

void removeNode(DLLNode *node) {
	DLLNode *prev = node->prev;
	DLLNode *next = node->next;
	prev->next = next;
	next->prev = prev;
}

int removeNodeFromTail() {
	DLLNode *temp = tail->prev;
	removeNode(temp);
	return temp->key;
}

// This move to head function is required for implementing the cache
void moveToHead(DLLNode *node) {
	cout<<"Accessed the key "<<node->key<<endl;
	removeNode(node);
	addNodeatHead(node);
}

int get(int k) {
	if(cache.count(k) == 0) {
		cout<<"Value is not present in the cache, please insert it first\n";
		return INT_MIN;
	}
	DLLNode* node = cache[k];
	moveToHead(node);
	return node->value;
}

void put(int k, int v) {
	if(cache.count(k) == 0) {
		DLLNode *node = new DLLNode(k, v);
		cache[k] = node;
		cout<<"Added a new key "<<k<<endl;
		addNodeatHead(node);

		capacity++;

		if(capacity > size) {
			int removedKey = removeNodeFromTail();
			cout<<"As the cache is full we need to remove the key "<<removedKey<<endl;
			cache.erase(removedKey);
			capacity--;
		}
	} else {
		DLLNode *node = cache[k];
		node->value = v;
		moveToHead(node);
	}
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	cout<<"Please enter the size of the cache\n";
	cin>>size;
	cout<<"Size of cache is "<<size<<endl;
	head->next = tail;
	tail->prev = head;

	int q;
	cin>>q;
	while(q--) {
		char ch;
		cin>> ch;
		int k, v;
		if(ch == 'p') {
			// put
			cin>>k>>v;
			put(k, v);
		} else {
			// get
			cin>>k;
			int value = get(k);
			cout<<"Value for key "<<k<<" is "<<value<<endl;
		}
	}

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
