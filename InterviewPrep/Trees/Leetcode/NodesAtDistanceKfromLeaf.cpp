#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// TreeNode class for a node of a Binary Search Tree
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// utility function to display a binary tree
void display(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    string str = "";

    str += node->left == NULL ? "." : to_string(node->left->val);
    str += " <= " + to_string(node->val) + " => ";
    str += node->right == NULL ? "." : to_string(node->right->val);

    cout << str << endl;

    display(node->left);
    display(node->right);
}

// This is a functional problem. You have to complete this function.
// It takes as input the root node of tree and K. It should return the required count.

vector<TreeNode*> result;
int counter = 0;
void helper(TreeNode* node, int k, vector<TreeNode*> &temp) {
    if (node == NULL) {
        return;
    }
    if (node->left == NULL and node->right == NULL) {

        if (temp.size() >= k and temp[temp.size() - k] != NULL) {
            result.push_back(temp[temp.size() - k]);
            counter++;
            temp[temp.size() - k] = NULL;
        }

        return;
    }
    temp.push_back(node);
    helper(node->left, k, temp);
    helper(node->right, k, temp);
    temp.pop_back();
}

int KDistantfromLeaf(TreeNode* node, int k) {
    // write your code here.
    vector<TreeNode*> temp;
    helper(node, k, temp);
    return counter;
}

//Don't change code of utility function.
TreeNode* stringToTreeNode(string &input) {
    int first = input.find_first_not_of(' ');
    int last = input.find_last_not_of(' ');
    input = input.substr(first, (last - first + 1));
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ' ');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();
        if (!getline(ss, item, ' ')) {
            break;
        }

        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ' ')) {
            break;
        }

        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);

        }
    }
    return root;
}

int main(int argc, char** argv) {
    string line;
    getline(cin, line);
    int k;
    cin >> k;
    TreeNode* root = stringToTreeNode(line);
    cout << KDistantfromLeaf(root, k) << endl;
}