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
    
    TreeNode* prev;
    TreeNode* head;

    void b2ll(TreeNode* root) {
        if(root == NULL) return;
         b2ll(root->left);
         // to do
         if(prev == NULL) {
            head = root;
         } else {
            root->left = prev;
            prev->right = root;
         }
         prev = root;
         b2ll(root->right);
         
    }
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}