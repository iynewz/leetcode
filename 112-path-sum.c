/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// 暴力 找到每一个 root to leaf 的和， 因为 Node.val 可以是负数
// 递归 对下一个root 考察是否等于 sum - root->val


bool hasPathSum(struct TreeNode* root, int targetSum){
    if (root == NULL) {
        return false;
    }
    if (root->val == targetSum && root->left == NULL && root->right == NULL) {
        return true;
    }
    return (hasPathSum( (root->left), (targetSum - root->val) ) ) || (hasPathSum((root->right), (targetSum - root->val)));
}

