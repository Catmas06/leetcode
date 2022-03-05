#define _CRT_SECURE_NO_WARNINGS 1
/*
	136.只出现一次的数字
		给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

	思想 -先排序，再对排序好的数组进行判断，每两个元素判断一次是否相等，相等则继续，不相等则直接返回当前元素
*/
#include<stdio.h>
#include<stdlib.h>

int cmp_int(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int singleNumber(int* nums, int numsSize) {
	qsort(nums, numsSize, sizeof(nums[0]), cmp_int);
	int i;
	for (i = 0; i < numsSize-1; i+=2) {
		if (nums[i] == nums[i + 1])	continue;
		else {
			return nums[i];
		}
	}
	return nums[i];
}