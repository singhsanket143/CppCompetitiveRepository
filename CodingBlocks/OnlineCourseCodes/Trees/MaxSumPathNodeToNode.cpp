#include <iostream>
using namespace std;
// Time, Space - O(N)
class TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
    
    int globalMax = INT_MIN;
    int maxPathNode2Node(TreeNode* root) {
        // Base case
        if(root == NULL) return 0;
        // Recursive work
        int ls = maxPathNode2Node(root->left); // LST
        int rs = maxPathNode2Node(root->right); // RST
        // Self work
        int cand1 = root->val;
        int cand2 = ls + root->val;
        int cand3 = rs + root->val;
        int cand4 = ls + rs + root->val;
        globalMax = max(cand1, max(cand2, max(cand3, max(cand4, globalMax))));
        return max(ls, max(rs, 0)) + root->val;// My contribution to my parent
    }
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}