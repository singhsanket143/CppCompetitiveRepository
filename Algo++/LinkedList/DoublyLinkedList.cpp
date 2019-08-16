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

void reverse(Node *&head) {
	Node* temp = NULL;
	Node* curr = head;
	while(curr != NULL) {
		temp = curr->prev;
		curr->prev= curr->next;
		curr->next = temp;
		curr = curr->prev;
	}
	if(temp!=NULL) {
		head = temp->prev;
	}
}

Node* merge(Node *a, Node *b) {
	if(a == NULL) {
		return b;
	} else if(b == NULL) {
		return a;
	}

	if(a->data < b->data) {
		a->next = merge(a->next, b);
		a->next->prev = a;
		a->prev = NULL;
		return a;
	} else {
		b->next = merge(a, b->next);
		b->next->prev = b;
		b->prev = NULL;
		return b;
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
