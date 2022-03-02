#define _CRT_SECURE_NO_WARNINGS 1
/*
	189. 轮转数组
		给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
	思想：
		- i从第0为开始，向后寻找当前数据转移后应存放的位置，并用temp变量保存目标位置源数据
		- i=k时，遍历停止并返回
		- 每当产生一个temp，立即向后找到该temp的目标存放位置，直至目标位置小于k时，完成最后一次存放
*/

//空间换时间
void rotate01(int* nums, int numsSize, int k) {
	//传入数组为空或不需要修改
	if (numsSize == 0) return;
	k %= numsSize;
	if (!k) return;
	//创建辅助数组,存放轮转后的值
	int* ret = (int*)malloc(sizeof(int) * numsSize);
	int count = 0;
	while (count < numsSize) {
		ret[(count+k)%numsSize] = nums[count++];
	}
	for (count = 0; count < numsSize;count++) {
		nums[count] = ret[count];
	}
	return;
}