#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

extern int** threeSum4(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

int main() {
	int nums[] = { -1,0,1,2,-1,-4 };
	int numsSize = sizeof(nums) / sizeof(int);
	int returnSize ;
	int* returnColumnSizes;
	for (int i = 0; i < numsSize; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n----------------------------\n");
	int** ret;
	ret = threeSum4(nums, numsSize, &returnSize, &returnColumnSizes);
	for (int i = 0; i < numsSize; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n----------------------------\n");
	int i = 0, j = 0;
	for (int i = 0; i < returnSize; i++) {
		printf("[%d %d %d]\n",ret[i][0], ret[i][1], ret[i][2]);
	}
	printf(" numsSize = %d\n", numsSize);
	printf(" returnSize = %d\n", returnSize);
	return 0;
}

/*
int main()
{
    int nums[6] = { -1, 0, 1, 2, -1, -4 };
    int numsSize = 6;
    int returnSize;// 表示返回的二维数组的行数
    int** returnColumnSizes = NULL;// 指向列数组指针的指针
    // 注意：列数组在哪我们无从得知，也不需要知道，
    // 我们只要知道有个一阶指针指向它就行了，我把它叫做列数组指针
    int** ans = threeSum(nums, numsSize, &returnSize, returnColumnSizes);
    // &returnSize 引用传值
    // 最后一个参数我认为也可以是 int *returnColumnSize，然后传入&returnColumnSizes，效果是一样的
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < (*returnColumnSizes)[i]; j++)
            printf("%d", ans[i][j]);
        printf("\n");
    }
    return 0;
}
*/