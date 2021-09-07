_int maxArea(int* height, int heightSize){
    int water = 0;
    int *l = height;
    int *r = l + heightSize - 1;
    while (l < r) {
        int h = *l < *r ? *l : *r;
        int w = (r - l) * h;
        if (w > water) {
            water = w;
        }
        while (*l <= h && l < r) l++;
        while (*r <= h && l < r) r--;
    }
    return water;
}
