#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
	char ch;
	bool isTerminal;
	unordered_map<char, Node*> children;
	Node(char ch) {
		this->ch = ch;
		this->isTerminal = false;
	}
};

class Trie {
public:
	Node *root;

	Trie() {
		this->root = new Node('\0');
	}

	void insert(string str) {
		Node *temp = root;
		for(int i = 0; i < str.size(); i++) {
			char ch = str[i];
			if(temp->children.count(ch)) {
				// found the child
				temp = temp->children[ch];
			} else {
				Node *n = new Node(ch);
				temp->children[ch] = n;
				temp = n;
			}
		}
		temp->isTerminal = true;
		return;
	}

	bool search(string str) {
		Node *temp = root;
		for(int i = 0; i < str.size(); i++) {
			char ch = str[i];
			if(temp->children.count(ch)) {
				// found the child
				temp = temp->children[ch];
			} else {
				return false;
			}
		}
		return temp->isTerminal;
	}

	void dfs(Node *root, string pre, string output) {
		if(root == NULL) return;
		if(root->isTerminal) cout<<pre+output<<endl;
		for(auto ch: root->children) {
			dfs(ch.second, pre, output+ch.first);
		}
	}

	void print_strings_with_prefix(string pre) {
		Node *temp = this->root;
		for(int i = 0; i < pre.size(); i++) {
			char ch = pre[i];
			if(temp->children.count(ch)) {
				temp = temp->children[ch];
			} else {
				return;
			}
		}
		dfs(temp, pre, "");
	}

};

int main(int argc, char const *argv[])
{

	int t;
	cin>>t;
	Trie tr;
	while(t--) {
		string s;
		cin>>s;
		tr.insert(s);
	}
	// int q;
	// cin>>q;
	// while(q--) {
	// 	string qs;
	// 	cin>>qs;
	// 	cout<<"String "<<qs<<" is "<<(tr.search(qs) ? "present" : "not present")<<endl;
	// }
	string p;
	cout<<"Enter the prefix\n";
	cin>>p;
	tr.print_strings_with_prefix(p);
	
	return 0;
}