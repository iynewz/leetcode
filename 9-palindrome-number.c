

bool isPalindrome(int x){
    if(x < 0) {
        return false;
    }
    else if(x == 0) { // 太久不写代码了这里错写成 = 
        return true;
    }
    
    // 把输入数字各个数位倒序放入一个数组 ch
    int a[100];
    int count_digit = 0;
    while(x != 0) {
        int digit = x % 10;
        x = x / 10;
        a[count_digit] = digit;
        count_digit += 1;
    }
    printf("count_digit=%d", count_digit);
    
    for (int i = 0; i < count_digit; i++) {
        if(a[i] != a[count_digit - i - 1]) {
            return false; // 这里不能判断 == ， return true，因为会导致只判断头尾部分后停下来，没有判断中间。。。
        }   
    }
    return true;    
}