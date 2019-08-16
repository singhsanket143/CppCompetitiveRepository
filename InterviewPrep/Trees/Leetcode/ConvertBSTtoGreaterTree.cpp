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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) {
            return root;
        }
        convertBST(root->right);
        int temp = root->val;
        root->val += sum;
        sum+=temp;
        convertBST(root->left);
        
        return root;
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
