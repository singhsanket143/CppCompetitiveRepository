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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
         queue<TreeNode*> qu;
         qu.push(root);
         while(!qu.empty()) {
             int count = qu.size();
             int temp = count;
             double sum = 0;
             while(temp--) {
                 TreeNode *rem = qu.front();
                 qu.pop();
                 sum+=rem->val;
                 if(rem->left!=NULL) {
                     qu.push(rem->left);
                 }
                 if(rem->right!=NULL) {
                     qu.push(rem->right);
                 }
             }
             double value = sum/count;
             result.push_back(value);
         }
         return result;
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
