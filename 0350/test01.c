#define _CRT_SECURE_NO_WARNINGS 1
/*
	350. Intersection of Two Arrays II
		Given two integer arrays nums1 and nums2, return an array of their intersection
		Each element in the result must appear as many times as it shows in both arrays
		And you may return the result in any order.

	- 思想
		- 题目给定的两数组长度不超过1000
		- 给定的数组元素值 0~1000
		创建两个长度为1000的数组，分别对nums1与nums2遍历
		每遍历到一个元素，就将其对应数组下标的元素值+1
		最后用两个指针遍历辅助数组，输出两个指针所指的最小值
*/
#include<stdio.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size,int* returnSize) {
	int arr1[1001] = { 0 };
	int arr2[1001] = { 0 };
	static int ret[1000];
	for (int i = 0; i < nums1Size; i++) {
		arr1[nums1[i]] ++;
	}
	for (int i = 0; i < nums2Size; i++) {
		arr2[nums2[i]] ++;
	}
	*returnSize = 0;
	for (int i = 0; i < 1001; i++) {
		if (arr1[i] > 0 && arr2[i] > 0) {
			int temp = arr2[i] > arr1[i] ? arr1[i] : arr2[i];
			while (temp) {
				ret[(*returnSize)++] = i;
				temp--;
			}
		}
	}
	return ret;
}

int main() {
	int nums1[] = { 1000,1000,1000 };
	int nums2[] = { 1000,1000 };
	int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
	int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
	int returnSize = 0;
	int *ret = intersect(nums1, nums1Size, nums2, nums2Size, &returnSize);
	for (int i = 0; i < returnSize;i++) {
		printf("%d ", ret[i]);
	}
	return 0;
}
