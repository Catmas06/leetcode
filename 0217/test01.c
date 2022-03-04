#define _CRT_SECURE_NO_WARNINGS 1
// 217. 存在重复元素
//给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
#include<stdio.h>
#include<stdbool.h>
//#include<stdlib.h>

//快排 -划分函数
int partition(int* nums, int low, int high) {
	int pivot = nums[low];
	while (low < high) {
		while (low < high && nums[high] >= pivot)
			high--;
		if (low < high) {
			nums[low] = nums[high];
		}
		while (low < high && nums[low] <= pivot)
			low++;
		if (low < high) {
			nums[high] = nums[low];
		}
	}
	nums[low] = pivot;
	return low;
}

//快排 -主体
void qsort(int* nums, int low, int high) {
	if (low > high) return;
	int pivot = partition(nums, low, high);
	qsort(nums, low, pivot - 1);
	qsort(nums, pivot + 1, high);
	return;
}

void printf_t(int *arr,int arrSize) {

	for (int i = 0; i < arrSize; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}

bool containsDuplicate01(int* nums, int numsSize) {
	qsort(nums, 0, numsSize - 1);
	printf_t(nums, numsSize);
	for (int i = 0; i < numsSize - 1; i++) {
		if (nums[i] == nums[i + 1])
			return true;
	}
	return false;
}


int main() {	
	int arr[] = { 1,2,4,4,5,56,56,7 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, 0, arrSize - 1);
	containsDuplicate01(arr, arrSize);
	return 0;
}