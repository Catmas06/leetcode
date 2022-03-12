#define _CRT_SECURE_NO_WARNINGS 1
/*
	1. 两数之和
		给定一个整数数组 nums 和一个整数目标值 target
		请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
		你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
		你可以按任意顺序返回答案。
		- 只存在一个有效答案
	思想
		- 先对数组快排
		- 设置l、r两个指针指向表头表尾，将所指元素相加
		- nums[l]+nums[r]=target 返回两元素
		-                <target l++
		-                >target r--
*/
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp_int(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int* temp_nums = (int*)malloc(sizeof(int) * numsSize);
	for (int i = 0; i < numsSize; i++) temp_nums[i] = nums[i];
	//对nums排序
	qsort(temp_nums, numsSize, sizeof(temp_nums[0]), cmp_int);
	*returnSize = 2;
	int* ret = (int*)malloc(sizeof(int) * 2);
	int l = 0, r = numsSize - 1;
	//假设有唯一解，则l、r不可能指向同一个元素
	while (l < r) {
		//找到唯一解
		if (temp_nums[l] + temp_nums[r] == target) {
			ret[0] = temp_nums[l];
			ret[1] = temp_nums[r];
			break;
		}
		//加和偏小
		else if (temp_nums[l] + temp_nums[r] < target) l++;
		//加和偏大
		else r--;
	}
	l = 0;
	while (l < numsSize) {
		if (nums[l] == ret[0]) {
			ret[0] = l;
			break;
		}
		l++;
	}
	r = 0;
	while (r < numsSize) {
		if (r != l && nums[r] == ret[1]) {
			ret[1] = r;
			break;
		}
		r++;
	}
	return ret;
}

int main() {
	int nums[] = { 3,2,3 };
	int returnSize = 0;
	twoSum(nums, sizeof(nums) / sizeof(nums[0]), 6, &returnSize);
}