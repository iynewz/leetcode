/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



//BST 表示，Vals(root->left) <= root->val <= Vals(root->right) 
// 对于每一个节点 ， 节点左子树元素的值 <= 根节点值 <= 节点右边子树元素的值
/* build(arr, l, r){
    if l > r : return
    m = l + (r - l) / 2
    root = 
    root.left = build(arr, l, m-1)
    root.right = build(arr, m+1, r)
    return root
}

*/ 

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    int l = 0;
    int r = numsSize;
    int m = l + (r - l) / 2;
        
    struct TreeNode* arr = (struct TreeNode*)malloc(sizeof(struct TreeNode) * 1);
    if (numsSize == 0) {
        return NULL;
    }  
    
    arr->val = nums[m];
    arr->left = sortedArrayToBST(nums, m);
    arr->right = sortedArrayToBST(nums + m + 1, r - m - 1);
    return arr;
}