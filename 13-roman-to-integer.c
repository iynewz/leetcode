

int romanToInt(char* s){  //s 是个数组，s[0], s[1], ... , 表示每个罗马数字
    int value[100]; // 这个数组开多大，ascii 中 z 对应 90
    value['I'] = 1; // 记得加单引号
    value['V'] = 5;
    value['X'] = 10;
    value['L'] = 50;
    value['C'] = 100;
    value['D'] = 500;
    value['M'] = 1000;
    value['\0'] = 0;
    int sum = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        sum += value[s[i]];
        if(value[s[i]] < value[s[i+1]]) {
            sum -= 2 * value[s[i]];
        }
        
    }
    return sum;
}