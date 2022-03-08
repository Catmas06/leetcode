#define _CRT_SECURE_NO_WARNINGS 1
/*
	283. 移动零
		给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
		请注意 ，必须在不复制数组的情况下原地对数组进行操作。
	思想
		- 用两个指针l、r，从0开始遍历数组，起始位置相同
		- 当r指向非0元素，l、r都向后移动一位
			- 当l、r指向不同位置时，将r所指内容放入l中，并都向后移动一位
		- 当r指向0元素，仅r向后移动一位
		- 当r遍历至表尾，将 [l、r) 内的值全部置0
*/
void moveZeroes(int* nums, int numsSize) {
	int l = 0, r = 0;
	while (r < numsSize) {
		if (nums[r] != 0) {
			if (l != r) {
				nums[l] = nums[r];
			}
			l++;
			r++;
		}
		else {
			r++;
		}
	}
	while (l < numsSize) {
		nums[l++] = 0;
	}
	return;
}