#include<iostream>
using namespace std;
//------------Node Class
class TreeNode{
public:
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

TreeNode* buildUsingPre() {
	int d;
	cin>>d;
	if(d == -1) return NULL;
	TreeNode* root = new TreeNode(d);
	root->left = buildUsingPre();
	root->right = buildUsingPre();
	return root;
}

void preorder(TreeNode* root) {
	if(root == NULL) return;
	cout<<root->data<<", ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(TreeNode* root) {
	if(root == NULL) return;
	inorder(root->left);
	cout<<root->data<<", ";
	inorder(root->right);
}

void postorder(TreeNode* root) {
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<", ";
}

int height(TreeNode* root) {
	if(root == NULL) return 0;
	int left = height(root->left);
	int right = height(root->right);
	return max(left, right) + 1;
}

void printAtLevelK(TreeNode* root,int k){
	
}

void levelOrderRecursive(TreeNode* root) {
	
}

int main(int argc, char const *argv[])
{
	TreeNode* root = buildUsingPre();
	preorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	cout<<height(root);
	cout<<endl;
	return 0;
}