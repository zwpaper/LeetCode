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
    int maxDepth(TreeNode *root) {
        return depth( root, 0 );
    }
    int depth(TreeNode *node, int d)
    {
    	if( node == NULL )
    		return d;
    	return max( depth( node->left, d + 1 ),
    		depth( node->right, d + 1 ));
    }
    int max( int a, int b )
    {
    	return (a > b ? a : b);
    }
};