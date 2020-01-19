#include <iostream>
#include "vector"
using namespace std;
// Time, Space - O(N)
class TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
    
    vector<int> v;
    int max_level = -1;
    void helper(TreeNode* root, int level) {
        if(root == NULL) return;
        if(level > max_level) {
            max_level = level;
            v.push_back(root->val);
        }
        helper(root->right, level+1);
        helper(root->left, level+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        // Logic
        helper(root, 0);
        return v;
    }
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}