#include<stdio.h>
#include<string.h>
#define N 1111111

int main()
{
    int arr[N];
    for (int i = 0; i < 100; i++){
        // memset(arr, 0, sizeof(int) * N);
        
        for(int k = 0; k < N; k++){
            arr[k] = 0;
        }
    }
    return 0;
}


