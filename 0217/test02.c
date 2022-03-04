#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<stdbool.h>

int cmp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

bool containsDuplicate02(int* nums, int numsSize) {
	qsort(nums, numsSize, sizeof(int), cmp);
	for (int i = 0; i < numsSize - 1; i++) {
		if (nums[i] == nums[i + 1])
			return true;
	}
	return false;
}
