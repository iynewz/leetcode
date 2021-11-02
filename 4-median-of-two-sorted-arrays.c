int merged[2020];

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int sumSize = nums1Size + nums2Size;
    double ans;
    
    // maerge two arrays
    for(int i = 0, j = 0, k = 0; ; ) {
        if ((i < nums1Size && j < nums2Size && nums1[i] <= nums2[j]) || (j == nums2Size && i < nums1Size)) {
            merged[k] = nums1[i];
            i++;
            k++;
        }
        else if ((i < nums1Size && j < nums2Size && nums1[i] > nums2[j]) || (i == nums1Size && j < nums2Size)) {
            merged[k] = nums2[j];
            j++;
            k++;
        }
        else break;
    }
    
    // for (int i = 0;i < sumSize; i++) {
   //      printf("%d ", merged[i]);
  //   }
    
    if (sumSize % 2) { //  如果 sumSize 是奇数
        ans = (double) merged[sumSize / 2];
    }
    else {
        ans = (merged[sumSize / 2 - 1] + merged[sumSize / 2 ]) * 0.5;
    }
    return ans;
}