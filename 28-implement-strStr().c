

int strStr(char * haystack, char * needle){
    int h = 0, n = 0; //初始化指针
    int hayL = strlen(haystack);
    int needleL = strlen(needle);
    if(needleL == 0) {
        return 0;
    }
    if(hayL == 0 && needleL != 0) {
        return -1;
    }
    while(h < hayL) {
        if(haystack[h] == needle[n]) {
            h++;
            n++;
            if(n == needleL) {   // 这里注意这个 if 应该是嵌套在上面的 if 里面
                return(h - n);
            }
        }
        
        else {
            h = h - n + 1;
            n = 0;
        }
        
    }
    return -1;
}