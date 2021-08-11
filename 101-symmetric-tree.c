/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool compare(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q != NULL || p != NULL && q == NULL) {
        return false;
    }
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p->val == q->val) {
        return (compare(p->left, q->right) && compare(p->right, q->left));
    }
    return false;
}


bool isSymmetric(struct TreeNode* root){
    return compare(root->left, root->right);
}