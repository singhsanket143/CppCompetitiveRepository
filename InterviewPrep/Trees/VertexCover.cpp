#include <iostream>
using namespace std;

class Node {
public:
	Node *left;
	Node *right;
	int vc;
	int data;
};

int vertexCover(Node *root) {
	if(root == NULL) {
		return 0;
	}
	if(root->left == NULL and root->right == NULL) {
		return 0;
	}
	if(root->vc!=0) {
		return root->vc;
	}
	int incl = 1 + vertexCover(root->left) + vertexCover(root->right);

	int excl = 0;
	if(root->left != NULL)
		excl += 1 + vertexCover(root->left->left) + vertexCover(root->left->right);
	if(root->right != NULL) 
		excl += 1 + vertexCover(root->right->left) + vertexCover(root->right->right);

	root->vc = min(incl, excl);
	return root->vc;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
