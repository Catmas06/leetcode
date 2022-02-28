#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//#include<string.h>

/*
	算法思想：
		1、先对传入的数组快排
		2、新建二级指针ret，用作返回值。ret内保存的是所有的、不重复的零排列数的地址。赋予numsSize*numsSize大小的空间
		4、用left、right指针指向数组操作区间的头与尾，用middle指向操作区间内。
		5、初值设定：left = 0, right = numsSize-1, middle = left+1
		6、循环：当区间处理完后，将left右移。当 nums[left] > 0 时，剩余所有排列均>0，直接返回当前结果
		5、当找到零排列后，malloc分配空间，修改其值，并将地址放入ret中
			将left右移，right左移，并跳过重复元素（收缩处理区间）

	注意：
		- Line 241: Char 15: runtime error: load of null pointer of type 'int *' [__Serializer__.c]
			返回了一个空指针，并free()了它
*/

int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int** threeSum4(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	//必选先给returnSize赋值，否则会对NULL执行free()，报错
	*returnSize = 0;
	//传入数组长度小于3 直接返回
	if (numsSize < 3) return NULL;
	qsort(nums, numsSize, sizeof(int), cmp);

	//给各个返回值初始化
	int** ret = (int**)malloc(sizeof(int*) * numsSize * numsSize);
	*returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize);

	int left, right, middle;

	//将left循环右移
	for (left = 0; left < numsSize; left++) {

		//left右移时去重
		if (left > 0 && nums[left] == nums[left - 1]) continue;

		//循环出口1
		if (nums[left] > 0) return ret;
		middle = left + 1;
		right = numsSize - 1;
		   
		//将middle循环右移
		while (middle < right) {
			int sum = nums[left] + nums[middle] + nums[right];
			//非零排列
			if (sum > 0) {
				right--;
			}
			else if (sum < 0) {
				middle++;
			}
			//找到零排列
			else {
				ret[*returnSize] = (int*)malloc(sizeof(int) * 3);
				ret[*returnSize][0] = nums[left];
				ret[*returnSize][1] = nums[middle];
				ret[*returnSize][2] = nums[right];
				(*returnColumnSizes)[*returnSize] = 3;
				//将returnSize所指向的值加1
				(*returnSize) += 1;

				//双向去重
				middle++;
				while (middle < right && nums[middle - 1] == nums[middle]) middle++;
				right--;
				while (middle < right && nums[right + 1] == nums[right]) right--;
			}
		}
	}
	return ret;
}
