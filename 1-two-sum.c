

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//时间复杂度 O(n^2) ， 还有更小的解法吗？

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < numsSize; i ++) {
        for(int j = i + 1; j < numsSize; j ++){
            if (nums[i] + nums[j] == target) {
                arr[0] = i;
                arr[1] = j;
            }
        }
    }
    return arr;
}