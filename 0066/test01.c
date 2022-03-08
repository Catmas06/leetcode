#define _CRT_SECURE_NO_WARNINGS 1
/*
	66.Plus One
		给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
		最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
		你可以假设除了整数 0 之外，这个整数不会以零开头。

	思想
		- 从digits[digitsSize-1]开始从后向前遍历
		- 若当前值<9,则直接+1后返回
		- 若当前值==9，则置为0，并向左一位重新判断
		- 若当前值==9，且下标为0，则置为0后，所有元素右移一位，并 disgits[0]=1
*/
#include<stdio.h>
#include<malloc.h>

int* shiftRight(int* digits,int digitsSize) {
	int* ret = (int*)malloc(sizeof(int) * (digitsSize+1));
	ret[0] = 1;
	for (int i = 0; i < digitsSize; i++) {
		ret[i + 1] = digits[i];
	}
	return ret;
}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
	//是否已完成修改，完成修改则flag置为0，跳出循环
	int flag = 1;
	int* ret = digits;
	for (int i = digitsSize - 1; i>=0 && flag; i--) {
		//可以直接+1
		if (digits[i] < 9) {
			digits[i] ++;
			*returnSize = digitsSize;
			break;
		}
		//需要向上进位，且不为首元素
		else if (i > 0 && digits[i] == 9) {
			digits[i] = 0;
			continue;
		}
		//需要向上进位，为首元素
		else {
			digits[i] = 0;
			ret = shiftRight(digits, digitsSize);
			*returnSize = digitsSize + 1;
			break;
		}
	}
	return ret;
}