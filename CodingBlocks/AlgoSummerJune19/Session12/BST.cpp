#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

Node* insertInBST(Node *root, int data) {
	if(root == NULL) {
		root = new Node(data);
		return root;
	}
	if(data < root->data) {
		root->left = insertInBST(root->left, data);
	} else {
		root->right = insertInBST(root->right, data);
	}
	return root;
}


void inorder(Node* root) {
	if(root == NULL) return;
	inorder(root->left);
	cout<<root->data<<", ";
	inorder(root->right);
}

void preorder(Node* root) {
	if(root == NULL) return;
	cout<<root->data<<", ";
	preorder(root->left);
	
	preorder(root->right);
}

bool search(Node* root, int key) {
	if(root == NULL) {
		return false;
	}
	if(root->data == key) {
		return true;
	}
	if(key < root->data) {
		return search(root->left, key); 
	} else {
		return search(root->right, key);
	}
}

Node* deleteFromBST(Node* root, int key) {
	if(root == NULL) {
		return NULL;
	}
	if(key < root->data) {
		root->left = deleteFromBST(root->left, key);
	} else if(key > root->data) {
		root->right = deleteFromBST(root->right, key);
	} else {
		if(root->left == NULL and root->right == NULL) {
			delete root;
			return NULL;
		} else if(root->right==NULL) {
			Node *temp = root->left;
			delete root;
			return temp;
		} else if(root->left == NULL) {
			Node *temp = root->right;
			delete root;
			return temp;
		} else {
			Node *right_root = root->right;
			Node *to_be_swap = right_root;
			while(to_be_swap->left != NULL) {
				to_be_swap = to_be_swap->left;
			}
			root->data = to_be_swap->data;
			root->right = deleteFromBST(root->right, root->data);
		}
	}
	return root;
}



int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	Node* root = NULL;
	while(n--) {
		int data;
		cin>>data;
		root = insertInBST(root, data);
	}
	inorder(root);
	cout<<endl;
	// cout<<search(root, 56)<<endl;
	// root= deleteFromBST(root, 150);
	// preorder(root);
	cout<<maxPathFromRoot2Leaf(root);
	return 0;
}
