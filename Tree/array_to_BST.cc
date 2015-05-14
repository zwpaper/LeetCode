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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* buildTree(vector<int>& list, int left, int right){
        if(right < left)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode *node = new TreeNode(list[mid]);
        node->left = buildTree(list, left, mid - 1);
        node->right = buildTree(list, mid + 1, right);
        return node;
    }
};
