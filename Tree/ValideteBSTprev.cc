/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
    	TreeNode *p = NULL;
    	return inOrder( root, p );    
    }

    bool inOrder(TreeNode *node, TreeNode *prev)
    {
    	if( node == NULL )
    		return true;
    	if( !inOrder( node, node->left ) )
    		return false;
    	if(( prev != NULL )&&( node->val <= prev->val ))
    		return false;
    	return inOrder( node->right, node );
    }
};