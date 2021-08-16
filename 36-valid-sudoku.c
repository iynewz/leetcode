// #include <stdio.h>
// char text[10];  //放在 main 函数外面，严格保证了数组中的每一项初始化都是 0

// int main() {
//     char text[10] = {'a'}; // 修改了第一项的值
//     for(int i = 0; i < 15 ; i++) { // 多打印了一些，所以打印出了内存中的随机位置
//         printf("%d ", text[i]);
//     }
//     return 0;
// }



bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    char tmpR[9][9] = {0};
    char tmpC[9][9] = {0};
    char tmpI[9][9] = {0};
    int num;
    int index;
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') {
                continue;
            }
            num = board[i][j] - '1';
            index = (i / 3) * 3 + j / 3;
            if(tmpR[i][num] | tmpC[j][num] | tmpI[index][num]) {
                return false;
            }
            tmpR[i][num] = tmpC[j][num] = tmpI[index][num] = 1;
        }
    }
    return true;
}