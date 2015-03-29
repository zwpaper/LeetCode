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
        if( root == NULL )
        {
        	return 0;	
        }
        int d = 1;
        stack<TreeNode> s;
        TreeNode node(0);
        root->val = 1;
        s.push(*root);
        while(!s.empty())
        {
        	node = s.top();
        	s.pop();
        	if( node.val > d )
        		d = node.val;
        	if( node.right != NULL )
        	{
        		node.right->val = node.val + 1;
        		s.push( *(node.right));
        	}
        	if( node.left != NULL )
        	{
        	    node.left->val = node.val + 1;
        		s.push(*(node.left));
        	}
        }
        return d;
    }
    
}; 