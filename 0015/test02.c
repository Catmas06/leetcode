#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
/*
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 3)
        return NULL;
    qsort(nums, numsSize, sizeof(int), cmp);
    int** ans = (int**)malloc(sizeof(int*) * numsSize * numsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize);
    int i, j, k, sum;
    for (k = 0; k < numsSize - 2; k++) {
        if (nums[k] > 0) {
            printf("returnSize = %d\n", *returnSize);
            return ans;
        }
        if (k > 0 && nums[k] == nums[k - 1])
            continue;
        i = k + 1;
        j = numsSize - 1;
        while (i < j) {
            sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                ans[*returnSize] = (int*)malloc(sizeof(int) * 3);
                (*returnColumnSizes)[*returnSize] = 3;
                ans[*returnSize][0] = nums[k];
                ans[*returnSize][1] = nums[i];
                ans[*returnSize][2] = nums[j];
                *returnSize += 1;
                while (i < j && nums[i] == nums[++i]);
                while (i < j && nums[j] == nums[--j]);
            }
            else if (sum > 0)
                j--;
            else
                i++;
        }
    }
    printf("returnSize = %d\n", *returnSize);
    return ans;
}
*/