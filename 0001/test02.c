#define _CRT_SECURE_NO_WARNINGS 1
/*
	暴力解法
		从头至尾遍历，每指向一个x，向后寻找是否有[target-x]存在
		- 指针前面的都被处理过，因此每次只用向后寻找即可
*/
int* twoSum2(int* nums, int numsSize, int target, int* returnSize) {
	*returnSize = 2;
	for (int i = 0; i < numsSize-1; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				int ret[2] = { i,j };
				return ret;
			}
		}
	}
	return 0;
}