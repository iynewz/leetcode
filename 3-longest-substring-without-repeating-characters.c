int Max(int a, int b) {
    if(a > b) {
        return a;
    }
    else return b;
}

int lengthOfLongestSubstring(char * s){
    int n = strlen(s);
    int ans = 0;
   
    for(int l = 0; l < n; l++) {
        int seen[128];
        memset(seen, 0, sizeof(seen));
        int r = l;     
        while(r < n && !seen[s[r]] ) {
            seen[s[r]]++; // 将第一次出现的字母，标记+1 
            r++; 
            
        }
        ans = Max(ans, r - l);  
    }
    return ans;      
}