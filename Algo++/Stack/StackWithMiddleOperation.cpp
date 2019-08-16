#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* prev;
	Node* next;
	Node(int data) {
		this->data = data;
		this->prev = NULL;
		this->next = NULL;
	}
};

class Stack {
public:
	Node *head;
	Node *middle;
	int count;
	Stack() {
		this->count = 0;
		this->head = NULL;
		this->middle = NULL;
	}

	void push(int data) {
		Node* node = new Node(data);
		node->next = this->head;
		this->count += 1;
		if(this->count == 1) {
			this->middle = node;
		} else {
			this->head->prev = node;
			if(this->count & 1) {
				this->middle = this->middle->prev;
			}
		}
		this->head = node;
	}

	int pop() {
		if(this->count == 0) {
			cout<<"Stack Empty";
			return -1;
		}
		Node *head = this->head;
		int item = head->data;
		this->head = head->next;
		if(this->head != NULL) {
			this->head->prev = NULL;
		}
		this->count -= 1;
		if(!(this->count & 1)){
			this->middle = this->middle->next;
		}
		delete head;
		return item;
	}

	int middleElement() {
		if(this->count == 0) {
			cout<<"Stack Empty";
			return -1;
		}
		return this->middle->data;
	}
};

int main(int argc, char const *argv[])
{
	Stack *s = new Stack();
	s->push(10);
	s->push(20);
	s->push(30);
	s->push(40);
	s->push(50);
	cout<<s->middleElement();
	s->pop();
	cout<<s->middleElement();
	return 0;
}
