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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        if((abs(depth(root->left) - depth(root->right)) < 2)
            && isBalanced(root->left)
            && isBalanced(root->right))
            return true;
        return false;
    }
private:
    int depth(TreeNode *node){
        if(node == NULL)
            return 0;
        return 1 + max(depth(node->left), depth(node->right));
    }
    int max(int a, int b){
        return a > b ? a : b;
    }
};
