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
        if( root == NULL )
        	return true;
        midOrder( root );
        return isOrdered( list );

    }
    std::vector<int> list;
    void midOrder( TreeNode *node )
    {
    	if( node == NULL )
    		return ;
    	midOrder( node->left );
    	list.push_back(node->val);
    	midOrder( node->right );

    }
    bool isOrdered(std::vector<int> &v)
    {
    	for(std::vector<int>::iterator i = v.begin(); ++i != v.end(); )
    	{
    		if( *i >= *(i + 1) )
    			return false;
    	}
    	return true;
    }
};