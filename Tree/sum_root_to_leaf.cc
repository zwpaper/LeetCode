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
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
        int num = 0;
        sum = 0;
        recursiveSum(root, num);
        return sum;
    }
private:
    void recursiveSum(TreeNode* node, int n){
        n = 10 * n + node->val;
        if(node->left != NULL)
            recursiveSum(node->left, n);
        if(node->right != NULL)
            recursiveSum(node->right, n);
        if(node->left == NULL && node->right == NULL)
            sum += n;
    }
    int sum;
};
