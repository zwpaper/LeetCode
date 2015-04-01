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
    bool isSameTree(TreeNode *p, TreeNode *q) {
    	if(p == q)
    		return true;
    	else
        	return frontCampare( p, q );
	}

    bool frontCampare( TreeNode *node1, TreeNode *node2 )
    {
    	if( node1 == node2 == NULL )
    		return true;
    	else if( node1->val == node2->val )
    	{
    		bool inFlag = true;
    		if((( node1->left == NULL ) && ( node2->left != NULL )) ||
    	        (( node1->left != NULL ) && ( node2->left == NULL )))
    			return false;
    		else 
    			inFlag = frontCampare( node1->left, node2->left );

    		if( inFlag == false )
    			return false;
    		else
    		{
    			if((( node1->right == NULL ) && ( node2->right != NULL )) ||
    	        (( node1->right != NULL ) && ( node2->right == NULL )))
    				return false;
    			else
    				return frontCampare( node2->right, node2->right );
    		}
    	}
    	else
    		return false;
    }
};