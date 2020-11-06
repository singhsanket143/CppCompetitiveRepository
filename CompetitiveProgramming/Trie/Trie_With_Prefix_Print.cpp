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
#define pb 				emplace_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
#define token(str,ch)	(std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> trie;

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

class Node {
public:
	char data;
	bool terminal;
	ump<char, Node*> children;

	Node(char ch) {
		this->data = ch;
		this->terminal = false;
	}
};

class Trie {
public:
	Node *root;
	int count;
	Trie() {
		this->root = new Node('\0');
		this->count = 0;
	}
	void insert(string str) {
		Node *temp = this->root;
		loop(i, 0, str.size() - 1) {
			char ch = str[i];
			if(temp->children.count(ch)) {
				// found
				temp = temp->children[ch];
			} else {
				// not found
				Node *n = new Node(ch);
				temp->children[ch] = n;
				temp = n;
			}
		}
		temp->terminal = true;
		this->count++;
	}
	bool search(string str) {
		Node *temp = this->root;
		loop(i, 0, str.size() - 1) {
			char ch = str[i];
			if(temp->children.count(ch)) {
				// found
				temp = temp->children[ch];
			} else {
				// not found
				return false;
			}
		}
		return temp->terminal;
	}
	void helperDFS(Node *root, string str, string osf) {
		if(root == NULL) return;
		if(root->terminal) {
			cout<<str+osf<<endl;
		}
		for(auto ch : root->children) {
			helperDFS(ch.second, str, osf+ch.first);
		}
	}
	void prefix_range(string str) {
		Node *temp = this->root;
		loop(i, 0, str.size() - 1) {
			char ch = str[i];
			if(temp->children.count(ch)) {
				// found
				temp = temp->children[ch];
			} else {
				// not found
				return;
			}
		}
		helperDFS(temp, str, "");
	}
};

int main(int argc, char const *argv[]) {
	file_i_o();
	string str;
	int t;
	cin>>t;
	Trie tr;
	while(t--) {
		cin>>str;
		tr.insert(str);
	}
	int searchQueries;
	cin>>searchQueries;
	while(searchQueries--) {
		cin>>str;
		cout<<str<<" is "<<tr.search(str)<<endl;
	}
	int prefix;
	cin>>prefix;
	while(prefix--) {
		cin>>str;
		cout<<"All the prefixes are as follows:\n";
		tr.prefix_range(str);
	}
	return 0;
}
