/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int max(int a, int b) {
    int max = a;
    if (b > a) {
        max = b;
    }
    return max;
}

int maxDepth(struct TreeNode* root){ // 该函数表明当前节点往下的深度，如果没有左右孩子，就是1，如果有左右孩子，就是（左右孩子深度较大值+1）
    if(root == NULL) {
        return 0;
    }
    // else if(root->left == NULL && root->right == NULL) {
    //     return 1;
    // }
    // else if (root->right == NULL) {
    //     return maxDepth(root->left)+1;
    // }
    // else if (root->left == NULL) {
    //     return maxDepth(root->right)+1;
    // }   
    return max(maxDepth(root->right), maxDepth(root->left))+1;
}
    

/*
    return root == NULL ? 0 : max(maxDepth(root->right), maxDepth(root->left))+1;
}
*/
