
// 枚举中间点，如果这个点是奇数
// babad  (1,1)
// 01234  (-1 3) changdu:3-(-1)-1 = 3
// babad  (2,22)
// 01234  (0 4) changdu:4-0-1 = 3
    
    
// cbbd (1,2)
// 0123 (-1,4) changdu:4-(-1)-1 = 2
// cbbddq (2,3)
// 012345 (0,5) changdu:5-0-1 = 4   
    


int expandAroundCenter(int i, int j, int n, char *s) {
    while(i >= 0 && j < n && s[i] == s[j]) {
    i--;
    j++;
    }
    return (j - i - 1); // Max Palindromic Substring length, len
}



char * longestPalindrome(char * s){
    int n = strlen(s);
    if (n == 1) {
        return s;
    }
    int max = 0;
    int begin;
    for(int i = 0; i < n; i++) {
        int len = expandAroundCenter(i, i, n, s);
        if (len > max) {
            max = len;
            begin = i - (len - 1) / 2;
        }
        len = expandAroundCenter(i, i+1, n, s);
        if (len > max) {
            max = len;
            begin = i - (len - 1) / 2;
        }
    }
    s[begin+max] = '\0';
    return s + begin;
}