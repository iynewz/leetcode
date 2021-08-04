/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void inorder(struct TreeNode* root, int* arr, int put, int* cnt) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, arr, put, cnt);
    if (put) {
        arr[(*cnt)++] = root->val;
    } else {
        (*cnt)++;
    }
    inorder(root->right, arr, put, cnt);
    // if (root->left != NULL) {
    //     inorder(root->left, arr, put);
    //     count++;
    // }
    // // push root->val into the array
    // (*arr++) = root->val;
    // if (root->right != NULL) {
    //     inorder(root->right, arr, put);
    //     count++;
    // }
}



int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int cnt = 0;
    
    inorder(root, NULL, 0, &cnt);
    *returnSize = cnt;
    if (cnt == 0) {
        return NULL;
    }
    cnt = 0;
    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
    inorder(root, arr, 1, &cnt);
    return arr;    
}