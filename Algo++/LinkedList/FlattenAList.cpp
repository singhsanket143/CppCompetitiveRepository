#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* right;
	Node* down;
	Node(int d) {
		data = d;
		right = NULL;
		down = NULL;
	}
};

void push(Node *&head, int data) {
	Node *n = new Node(data);
	n->down = head;
	head = n;
}

Node* merge(Node* a, Node* b) {
	if(a == NULL) {
		return b;
	}
	if(b == NULL) {
		return a;
	}
	Node* result;
	if(a->data < b->data) {
		result = a;
		result->down = merge(a->down, b);
	} else {
		result = b;
		result->down = merge(a, b->down);
	}
	return result;
}

Node* flatten(Node* root) {
	if(root == NULL or root->right == NULL) {
		return root;
	}
	return merge(root, flatten(root->right));
}



void print(Node *head) {
	while(head != NULL) {
		cout<<head->data<<" ";
		head = head->down;
	}
}

int main(int argc, char const *argv[])
{
	Node* root = NULL;
	push( root, 30 );
    push( root, 8 );
    push( root, 7 );
    push( root, 5 );
 
    push( ( root->right ), 20 );
    push( ( root->right ), 10 );
 
    push( ( root->right->right ), 50 );
    push( ( root->right->right ), 22 );
    push( ( root->right->right ), 19 );
 
    push( ( root->right->right->right ), 45 );
    push( ( root->right->right->right ), 40 );
    push( ( root->right->right->right ), 35 );
    push( ( root->right->right->right ), 20 );
    root = flatten(root);
 
    print(root);
	return 0;
}
