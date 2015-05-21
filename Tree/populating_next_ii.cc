/**
 * Populating Next Right Pointers in Each Node II
 *
 *
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL){ return; }
        TreeLinkNode *walker = root;
        TreeLinkNode *next_target = NULL;
        TreeLinkNode *first = (walker->left != NULL ? walker->left : walker->right);
        while(walker != NULL){
            if(walker->left != NULL && walker->right != NULL){
                walker->left->next = walker->right;
            }
            next_target = walker->next;
            while(next_target != NULL && next_target->left == NULL && next_target->right == NULL)
                next_target = next_target->next;
            if(next_target != NULL){
                if(walker->right != NULL)
                    walker->right->next = (next_target->left == NULL ? next_target->right : next_target->left);
                else if(walker->left != NULL)
                    walker->left->next = (next_target->left == NULL ? next_target->right : next_target->left);
            }
            if(next_target != NULL)
                walker = next_target;
            else{
                if(first == NULL)
                    break;
                walker = first;
                while(first->left == NULL && first->right == NULL && first->next != NULL)
                    first = first->next;
                first = (first->left != NULL ? first->left : first->right);
            }
        }
    }
};