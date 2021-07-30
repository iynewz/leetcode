
int getLucky(char* s, int k){
    int len = 0;
    int sum = 0;
    for (char* t = s; *t != 0; ++t) {
        sum = sum + ((*t - 'a' + 1) % 10) + ((*t - 'a' + 1) / 10);
    }
    
    printf("sum = %d\n", sum);
   

    for (int j = 1; j < k; j++) {
        int sum2 = 0;
        int tmp = sum;
        for (tmp != 0; tmp != 0; tmp /= 10) {
            sum2 += tmp % 10;
        }
        sum = sum2;
    }
    return sum;
