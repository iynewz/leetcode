/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int depth(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    else {
        int lDepth = depth(root->left);
        int rDepth = depth(root->right);
        if (lDepth > rDepth) {
            return lDepth + 1;
        }
        else return rDepth + 1;
    }
}

bool isBalanced(struct TreeNode* root){
    if (root == NULL) {
        return true;
    }
    int lh, rh;
    lh = depth(root->left);
    rh = depth(root->right);
    if (lh - rh > 1 || rh - lh > 1) {
        return false;
    }
    else return isBalanced(root->left) && isBalanced(root->right);
}