/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct Element { 
    struct TreeNode *node; 
    int depth; //记录树的当前深度
} queue[100011];


int minDepth(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    int head = 0;
    int tail = 0;
    queue[tail].node = root;
    queue[tail].depth = 1;
    tail++;
    int depth;
    while (head != tail) {
        struct TreeNode* node = queue[head].node; 
        depth = queue[head].depth;
        head++;
        
        if (node->left == NULL && node->right == NULL) {
            break;
        }
        if (node->left != NULL) {
            queue[tail].node = node->left;
            queue[tail].depth = depth+1;
            tail++;
        }
        if (node->right != NULL) {
            queue[tail].node = node->right;
            queue[tail].depth = depth+1;
            tail++;
        }   
    }
    return depth;
}