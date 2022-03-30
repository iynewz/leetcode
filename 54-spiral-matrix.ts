function spiralOrder(matrix: number[][]): number[] {
    if(matrix.length == 0 || matrix[0].length == 0) {
        return [];
    }

    let left = 0;
    let right = matrix[0].length - 1;
    let top = 0;
    let bottom = matrix.length - 1;
    let ans: number[] = [];

    while(left <= right && top <= bottom) {
        for(let i = left; i <= right; i++) {
            ans.push(matrix[top][i]);
        }
        for(let j = top + 1; j <= bottom; j++) {
            ans.push(matrix[j][right]);
        }
        if(left < right && top < bottom) {
            for(let i = right - 1; i >= left; i--) {
                ans.push(matrix[bottom][i]);
            }
            for(let j = bottom - 1; j >= top + 1; j--) {
                ans.push(matrix[j][left]);
            }
        }
        
        left++;
        right--;
        top++;
        bottom--;
    }
    return ans;
};