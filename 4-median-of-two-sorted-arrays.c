double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int sumSize = nums1Size + nums2Size;
    double ans = 0.0;
    
    // maerge two arrays
    for(int i = 0, j = 0, k; ; ) {
        if (i < nums1Size && j < nums2Size) {
            k = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        } else {
            if (i < nums1Size) {
                k = nums1[i++];
            } else if (j < nums2Size) {
                k = nums2[j++];
            } else {
                break;
            }
        }
        if (sumSize % 2 == 0) {
            if (i + j == sumSize / 2) {
                ans += k;
            } else if (i + j == sumSize / 2 + 1) {
                ans = (ans + k) * 0.5;
            }
        } else {
            if (i + j == (sumSize + 1) / 2) {
                ans = (double)k;
                break;
            }
        }
        // if ((i < nums1Size && j < nums2Size && nums1[i] <= nums2[j]) || (j == nums2Size && i < nums1Size)) {
        //     merged[k] = nums1[i];
        //     i++;
        //     k++;
        // }
        // else if ((i < nums1Size && j < nums2Size && nums1[i] > nums2[j]) || (i == nums1Size && j < nums2Size)) {
        //     merged[k] = nums2[j];
        //     j++;
        //     k++;
        // }
        // else break;
    }
    
    // for (int i = 0;i < sumSize; i++) {
   //      printf("%d ", merged[i]);
  //   }
    
    // if (sumSize % 2) { //  如果 sumSize 是奇数
    //     ans = (double) merged[sumSize / 2];
    // }
    // else {
    //     ans = (merged[sumSize / 2 - 1] + merged[sumSize / 2 ]) * 0.5;
    // }
    return ans;
}