

/**
 * Note: The returned array must be malloced, assume caller calls free().
   建一个数组a,初始化0，遍历score数组，a[score[i]] + 1, temp = scoreSize - {a[0]到a[]有多少}

*/

char **findRelativeRanks(int *score, int scoreSize, int *returnSize)
{
    int arr[10111];
    memset(arr, 0, sizeof(int) * 10111);
    *returnSize = scoreSize;
    // char** result;
    char **result = (char **)malloc(sizeof(char *) * scoreSize);
    int tmp = 0;
    for (int i = 0; i < scoreSize; i++)
    {
        arr[score[i]] = 1;
    }
    for (int i = 0; i < scoreSize; i++)
    {
        // arr[0] ~ arr[score[i]] total tmp
        for (int k = 0; k < score[i]; k++)
        {
            tmp += arr[k];
        }
        int rank = scoreSize - tmp;
        if (rank == 1)
        {
            result[i] = (char *)malloc(sizeof(char) * 11);
            sprintf(result[i], "%s", "Gold Medal");
        }
        else if (rank == 2)
        {
            result[i] = (char *)malloc(sizeof(char) * 13);
            sprintf(result[i], "%s", "Silver Medal");
        }
        else if (rank == 3)
        {
            result[i] = (char *)malloc(sizeof(char) * 13);
            sprintf(result[i], "%s", "Bronze Medal");
        }
        else
        {
            sprintf(result[i], "%s", scoreSize - tmp);
        }
    }
    return result;
}
