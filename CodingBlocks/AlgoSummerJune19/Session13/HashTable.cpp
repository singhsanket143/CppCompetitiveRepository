#include <iostream>
#define ll long long int
using namespace std;

template<typename T>
class Node {
public:
	string key;
	T value; 
	Node<T>* next;

	Node(string key, T value) {
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};

template<typename T>
class HashTable {
public:
	int cs;
	int ts;
	Node<T> **arr;
	HashTable(int ts=7) {
		this->cs = 0;
		this->ts = ts;
		arr = new Node<T>*[this->ts];
		for(int i=0;i<this->ts;i++) {
			arr[i] = NULL;
		}
	}

	void display() {
		for(int i=0;i<this->ts;i++) {
			Node<T>* temp = this->arr[i];
			if(temp == NULL) {
				cout<<"empty\n";
				continue;
			}
			while(temp!=NULL) {
				cout<<"("<<temp->key<<","<<temp->value<<") -> ";
				temp = temp->next;
			}
			cout<<endl;
		}
	}

	int hashFunc(string key) {
		ll sum = 0;
		ll factor = 1;
		for(int i=0;i<key.size();i++) {
			sum = (sum%this->ts) + ((int)(key[i])*factor)%this->ts;
			sum = sum%this->ts;
			factor = ((factor%this->ts)*(37%this->ts))%this->ts;
		}
		return (int)sum;
	}

	void rehash() {
		int old_size = this->ts;
		this->ts = this->ts*2;
		Node<T>** oldTable = this->arr;
		this->arr = new Node<T>*[this->ts];
		for(int i=0;i<this->ts;i++) this->arr[i] = NULL;

		for(int i=0;i<old_size;i++) {
			Node<T>* temp = oldTable[i];
			while(temp!=NULL) {
				insert(temp->key, temp->value);
				temp = temp->next;
			}
		}
	}

	void insert(string key, T value) {
		int idx = hashFunc(key);
		Node<T>* new_node = new Node<T>(key, value);
		if(this->arr[idx]==NULL) {
			this->arr[idx] = new_node;
		} else {
			new_node->next = this->arr[idx];
			this->arr[idx] = new_node;
		}
		this->cs++;
		double loadFactor = (double)(this->cs)/this->ts;
		if(loadFactor > 0.5) {
			rehash();
		}
	}

	T search(string key) {
		int idx = hashFunc(key);
		Node<T>* temp = this->arr[idx];
		while(temp!=NULL) {
			if(temp->key == key) {
				return temp->value;
			}
			temp = temp->next;
		}
		return NULL;
	}
	
};

int main(int argc, char const *argv[])
{
	HashTable<int> *hash = new HashTable<int>();
	(*hash).insert("mango", 27);
	(*hash).insert("apple", 7);
	(*hash).insert("appy", 2);
	(*hash).insert("apipie", 207);
	(*hash).insert("banana", 217);
	(*hash).insert("bananapie", 271);
	(*hash).insert("mangopie", 27);
	(*hash).insert("piepie", 272);
	(*hash).insert("applepie", 217);
	(*hash).insert("api", 27);	
	(*hash).display();
	int getValue = (*hash).search("api");
	//cout<<(*hash).search("api");
	if(getValue==NULL) {
		cout<<"Not found";
	} else {
		cout<<getValue;
	}
	return 0;
}
