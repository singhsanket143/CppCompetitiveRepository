#include <iostream>
using namespace std;

class Node {
public:
	char data;
	bool isTerminal;
	Node** children;

	Node(char data) {
		this->data = data;
		this->isTerminal = false;
		this->children = new Node*[26];
		for(int i=0;i<26;i++) {
			this->children[i] = NULL;
		}
	}
};

Node* insert(Node* root, string data) {
	Node* temp = root;
	for(int i=0;i<data.size();i++) {
		char ch = data[i];
		if(temp->children[ch-'a']==NULL) {
			temp->children[ch-'a'] = new Node(ch);
		}
		temp = temp->children[ch-'a'];
	}
	temp->isTerminal = true;
	return root;
}

bool search(Node* root, string word) {
	Node* temp = root;
	for(int i=0;i<word.size();i++){
		char ch = word[i];
		if(temp->children[ch-'a']==NULL) {
			return false;
		}
		temp = temp->children[ch-'a'];
	}
	return temp->isTerminal;
}

void recurse(Node* root, string word, string osf) {
	if(root->isTerminal == true) {
		cout<<word + osf + root->data<<endl;
	}
	Node* temp = root;
	for(int i=0;i<26;i++) {
		if(temp->children[i]!=NULL) {
			recurse(temp->children[i], word, osf+temp->data);
		}
	}
}

void startsWith(Node* root, string word) {
	Node* temp = root;
	for(int i=0;i<word.size();i++) {
		char ch = word[i];
		temp = temp->children[ch-'a'];
	}
	recurse(temp, word.substr(0, word.size()-1), "");
}

int main(int argc, char const *argv[])
{
	Node* root = new Node('\0');
	root = insert(root, "apple");
	root = insert(root, "app");
	root = insert(root, "api");
	root = insert(root, "appy");
	root = insert(root, "apgy");
	root = insert(root, "appipie");
	root = insert(root, "bag");
	root = insert(root, "bagged");
	root = insert(root, "boom");
	
	startsWith(root, "ap");

	return 0;
}
