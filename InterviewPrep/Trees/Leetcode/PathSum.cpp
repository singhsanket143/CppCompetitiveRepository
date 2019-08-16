#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* root, int sum, int sum_so_far) {
        if(root == NULL) {
            return false;
        }
        if(root->left == NULL and root->right==NULL) {
            return sum_so_far+root->val == sum; 
        }
        bool left = helper(root->left, sum, sum_so_far+root->val);
        bool right = helper(root->right, sum, sum_so_far+root->val);
        return left or right;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return helper(root, sum, 0);
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
