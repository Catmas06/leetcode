#define _CRT_SECURE_NO_WARNINGS 1
/*
nums = "----->-->"; k = 3
result = "-->----->";

reverse "----->-->" we can get "<--<-----"
reverse "<--" we can get "--><-----"
reverse "<-----" we can get "-->----->"
*/

//交换函数位置
void swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

//旋转函数
void reverse(int* nums, int left, int right) {
	while (left < right) {
		swap(&(nums[left++]), &(nums[right--]));
	}
}

//三次旋转
void rotate03(int* nums, int numsSize, int k) {
	if (!numsSize || !(k %= numsSize)) return;
	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, numsSize - 1);
}