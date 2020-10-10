#include <iostream>
using namespace std;
// Space  - O(N)
// Time - O(N)
// At most Single traversal
class TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Custom {
public:
	bool hasKey1;
	bool hasKey2;
	TreeNode* node; // Store the value of LCA
};

Custom* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
	// Base case
	if(root == NULL) return NULL;
	Custom* leftans = helper(root->left, p, q);
	if(leftans!=NULL and leftans->node!=NULL) {
		return leftans;
	} 
	Custom* rightans = helper(root->right, p, q);
	if(rightans!=NULL and rightans->node!=NULL) {
		return rightans;
	}
	Custom* result = new Custom();
	if (leftans!=NULL and rightans!=NULL) {
		result->node = root;
		result->hasKey1 = true;
		result->hasKey2 = true;
		return result;
	} else if(root->val == p->val) {
		result->hasKey1 = true;
		result->hasKey2 = (leftans)?leftans->hasKey2:false or (rightans)?rightans->hasKey2:false;
		if(result->hasKey1 and result->hasKey2) result->node = root;
		return result;
	} else if(root->val == q->val) {
		result->hasKey2 = true;
		result->hasKey1 = (leftans)?leftans->hasKey1:false or (rightans)?rightans->hasKey1:false;
		if(result->hasKey1 and result->hasKey2) result->node = root;
		return result;
	} else if(leftans) {
		return leftans;
	} else if(rightans) {
		return rightans;
	}
	return NULL;

}
    
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    Custom* result = helper(root, p, q);
    if(result==NULL) return NULL;
    else return result->node;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}