
int arr[11111];
int visited[11111];


int numSquares(int n){
    memset(visited, 0, sizeof(visited));
    int step = 0;
    int head = 0;
    int rear = 0;
    arr[rear++] = 0;
    visited[0] = 0; // 0 step
    
    while(head != rear) {
        // arr[head] 处理后放到尾部
        int val = arr[head++];
        step = visited[val];
        for(int i = 1; i <= 100; i++) {
            int target = val + i * i;
            if (target < n && visited[target] == 0) {
                arr[rear++] = target;
                visited[target] = step + 1;
            }
            if (target == n) {
                return step+1;
            }
            else if (target > n) {
                break;
            }
        }
       
    }
    return 0;
}

