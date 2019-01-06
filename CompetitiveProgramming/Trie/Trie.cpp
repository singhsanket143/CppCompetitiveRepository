#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
public:
	char data;
	unordered_map<char,Node*> children;
	bool terminal;
	char *name;

	Node(char d){
		data = d;
		terminal = false;
		name = NULL;
	}
};

class Trie{
	Node*root;
	int cnt;

public:
	Trie(){
		root = new Node('\0');
		cnt = 0;
	}
	void addWord(char w[]){

		Node*temp = root;
		for(int i=0;w[i]!='\0';i++){

			char ch = w[i];
			if(temp->children.count(ch)){
				temp = temp->children[ch];
			}
			else{
				Node*n = new Node(ch);
				temp->children[ch] = n;
				temp = n;
			}
		}
		temp->terminal = true;

	}
	bool search(char w[]){
		Node* temp = root;
		for(int i=0;w[i]!='\0';i++){

			char ch = w[i];
			if(temp->children.count(ch)==0){
				return false;
			}
			else{
				temp = temp->children[ch];
			}
		}
		return temp->terminal;
	}
};

int main(){


	Trie t;
	char words[][10] = {"a","hello","not","news","not"};
	char w[10];
	cin>>w;

	for(int i=0;i<5;i++){
		t.addWord(words[i]);
	}

	if(t.search(w)){
		cout<<w<<" found!";
	}
	else{
		cout<<w<<" not found!";
	}

	return 0;
}