#include<iostream>
#include<limits.h>
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {
    int data;
    std::cin>>data;
    Node *root;
    if(data != -1) {
        root = new Node(data);
    } else {
        return NULL;
    }
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void preOrder(Node* root) {
    if(root == NULL) return;
    std::cout<<root->data<<" ";
    preOrder(root->left);   
    preOrder(root->right);
}

void inOrder(Node* root) {
    if(root == NULL) return;

    inOrder(root->left);
    std::cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    std::cout<<root->data<<" ";
}

int height(Node* root) {
    if(root == NULL) return 0;

    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + std::max(lh, rh);
}

int maxEL(Node* root) {
    if(root == NULL) return INT_MIN;

    int lmax = maxEL(root->left);
    int rmax = maxEL(root->right);
    // return std::max({lmax, rmax, root->data});
    return std::max(std::max(lmax, rmax), root->data);
}

int main(int argc, char const *argv[])
{
    /* code */
    // 27 42 64 -1 -1 99 87 -1 -1 -1 33 18 -1 -1 22 -1 25 28 -1 -1 -1
    Node* root = buildTree();
    preOrder(root);
    std::cout<<"\n";
    inOrder(root);
    std::cout<<"\n";
    postOrder(root);
    std::cout<<"\n";
    std::cout<<height(root)<<"\n";
    std::cout<<maxEL(root)<<"\n";
    return 0;
}
