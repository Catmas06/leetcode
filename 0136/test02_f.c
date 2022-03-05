#define _CRT_SECURE_NO_WARNINGS 1
/*
	思想 
		- 异或运算 两个相同的数字异或，结果为0
		- a ^ a = 0 
		- 0 ^ a = a
*/

int singleNumber02(int* nums, int numsSize) {
	int ret = nums[0];
	for (int i = 1; i < numsSize; i++) {
		ret ^= nums[i];
	}
	return ret;
}