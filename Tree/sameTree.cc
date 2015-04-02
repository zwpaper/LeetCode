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
    	if(( node1 == NULL ) || ( node2 == NULL ))
    		return (( node1 == NULL ) && ( node2 == NULL ));
    	if( node1->val == node2->val )
	    {
    		bool inFlag = true;
    		inFlag = frontCampare( node1->left, node2->left );

    		if( inFlag == false )
    			return false;
    		else
    			return frontCampare( node1->right, node2->right );
    		
	    }
	    else
	        return false;
    }
};