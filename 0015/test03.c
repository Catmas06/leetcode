#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

int cmp3(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
int** threeSum3(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	printf("numsSize = %d\n", numsSize);
	*returnSize = 0;
	if (numsSize < 3)
		return NULL;
	qsort(nums, numsSize, sizeof(int), cmp3);
	int size = numsSize;
	int** ans = (int**)malloc(sizeof(int*) * size * size);
	*returnColumnSizes = (int*)malloc(sizeof(int) * size * size);
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
				(*returnSize) += 1;
				//当找到0排列时，两个指针都要移动
				i++;
				while (i < j && nums[i - 1] == nums[i]) i++;
				j--;
				while (i < j && nums[j + 1] == nums[j]) j--;
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