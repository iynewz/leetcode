// 递推，Dynamic Programming 的一种

int max(int a, int b) {
    return(a <= b ? b : a);
}

int maxSubArray(int* nums, int numsSize){
    int g[numsSize+2];
    int maxsum;
    g[0] = nums[0];
    for(int i = 1; i < numsSize; i++) {
         g[i] = max( nums[i], g[i-1] + nums[i] );
    }
    maxsum = g[0];
    for(int i = 0; i < numsSize; i++) {
        if (g[i] > maxsum) {
            maxsum = g[i];
        }
    }
    return maxsum;
}