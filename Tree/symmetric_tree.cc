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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return checkSymmetric(root->left, root->right);
    }
private:
    bool checkSymmetric(TreeNode *first, TreeNode *second){
        if(first == NULL && second == NULL)
            return true;        
        if(first == NULL ^ second == NULL)
            return false;
        if(first->val == second->val){
            return checkSymmetric(first->left, second->right) && checkSymmetric(first->right, second->left);
        }
        return false;
    }
};