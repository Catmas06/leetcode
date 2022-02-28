
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

/*
	关于 **returnColumSize
		在main函数中，此变量是一个一维数组，returnColumSize[i] = n
		表示返回的二维数组中，第i行有n个有效元素
		为了可以在函数中修改传递过来的变量，需要传入原一维数组的地址，即二级地址
*/

//相加，并返回一个组合数组
int* add(int* nums, int i, int j, int k) {
	if (i && j && k) {
		if (nums[i] + nums[j] + nums[k] == 0) {
			int* ret = malloc(3 * sizeof(int));
			ret[0] = nums[i];
			ret[1] = nums[j];
			ret[2] = nums[k];
			return ret;
		}
		else return NULL;
	}
	else return NULL;
}
/*
//遍历数组内的所有三元组合，计算其和是否为0
int** threeSum_1(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	*returnSize = 0;
	*returnColumnSizes = (int*)malloc(sizeof(int) * numsSize);
	qsort(nums, numsSize, sizeof(int), compare);
	for (int i = 0; i < 6; i++) {
		printf("%d ", nums[i]);
	}
	int left = 0, right, middle, count = 0, flag = 1;
	int** ret = (int**)malloc(sizeof(int) * numsSize * 3);
	while (left < numsSize - 3 && nums[left] <= 0) {
		right = numsSize - 1;
		middle = left + 1;
		while (flag && left < middle && middle < right) {
			//三和<0时，middle右移
			while (left < middle && middle < right && nums[left] + nums[middle] + nums[right] < 0) middle++;
			//判断三和是否为0
			if (left < middle && middle < right && nums[left] + nums[middle] + nums[right] == 0) {
				*((int*)ret + count * 3 + 0) = nums[left];
				*((int*)ret + count * 3 + 1) = nums[middle];
				*((int*)ret + count * 3 + 2) = nums[right];
				*returnColumnSizes[count] = 3;
				count++;
				flag = 0;
			}
			//三和>0时，right左移
			while (left < middle && middle < right && nums[left] + nums[middle] + nums[right] > 0) right--;
			//判断三和是否为0
			if (left < middle && middle < right && nums[left] + nums[middle] + nums[right] == 0) {
				*((int*)ret + count * 3 + 0) = nums[left];
				*((int*)ret + count * 3 + 1) = nums[middle];
				*((int*)ret + count * 3 + 2) = nums[right];
				*returnColumnSizes[count] = 3;
				count++;
				flag = 0;
			}
			middle++;
		}
		left++;
		if (flag == 0) {
			while (left < numsSize - 3 && nums[left] <= 0 && nums[left] == nums[left - 1])
				left++;
			flag = 1;
		}
	}
	//处理最终情况：left后不足4个元素
	if (left > numsSize - 3) {
		*returnSize = count;
		return ret;
	}
	else{
		if (nums[left] + nums[left + 1] + nums[left + 2] != 0) {
			*returnSize = count;
			return ret;
		}
		else {
			*((int*)ret + count * 3 + 0) = nums[left];
			*((int*)ret + count * 3 + 1) = nums[middle];
			*((int*)ret + count * 3 + 2) = nums[right];
			*returnColumnSizes[count] = 3;
			*returnSize = count + 1;
			return ret;
		}
	}
}
*/