char* longestCommonPrefix(char** strs, int strsSize){
    if (strsSize == 0) {
        return "";
    }
    if (strsSize == 1) {
        return strs[0];
    }
    // 每个和第一个单词比对，看有开头有多少重复
    for(int i = 1; i < strsSize; i++) {
      
		int j;
		for (j = 0; strs[i][j] == strs[0][j] && strs[i][j] != 0; j++); // strs[i] 的类型是 char*，是一个元素为 char 的数组,["",""],["flower","flower","flower","flower"]
		strs[0][j] = 0; // 改成 0 就能停下来
    }
    return strs[0];
}