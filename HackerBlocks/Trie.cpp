#include<iostream>
#include<unordered_map>
using namespace std;


class node{
public:
	char data;
	unordered_map<char,node*> m;
	bool terminal;
	node(char d){
		data = d;
		terminal = false;
	}
};

class trie{
	node*root;
	int total_words;

public:
	trie(){
		root = new node('\0');
		total_words= 0;
	}
	void addWord(char word[]){

		node* temp = root;

		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];

			if(temp->m.count(ch)==0){
				node*n = new node(ch);
				temp->m[ch] = n;
				temp = n;	
			}
			else{
				temp = temp->m[ch];
			}
		}
		temp->terminal = true;
	}
	bool lookup(char *word){

		node* temp = root;

		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];

			if(temp->m.count(ch)==0){
				return false;	
			}
			else{
				temp = temp->m[ch];
			}
		}
		return temp->terminal;
	}



};


int main(){


	return 0;
}