#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//递归求最大公约数gcd，最小公倍数lcm
//a、b不能为0
int gcd(int a, int b) {

	if (a % b == 0)
		return b;
	else return gcd(b, a % b);
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

//非递归求
int gcd2(int a, int b) {
	while (b) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a + b;
}

//时间换空间
void rotate02(int* nums, int numsSize, int k) {
	if (numsSize == 0) return;
	k %= numsSize;
	if (!k) return;
	int temp1, temp2, i, j;
	switch (numsSize % k) {
		//需要重复轮转
	case 0:
		for (i = 0; i < k; i++) {
			j = i;
			temp1 = nums[j];
			for (int count = 0; count < numsSize / k; count++) {
				temp2 = nums[(j + k) % numsSize];
				nums[(j + k) % numsSize] = temp1;
				temp1 = temp2;
				j = (j + k) % numsSize;
			}
		}
		break;
		//不需要重复轮转
	default:
		j = 0;
		for (i = 0; i < numsSize*k/lcm(numsSize,k); i++) {
			j = i;
			temp1 = nums[j];
			for (int count = 0; count < lcm(numsSize,k)/k; count++) {
				temp2 = nums[(j + k) % numsSize];
				nums[(j + k) % numsSize] = temp1;
				temp1 = temp2;
				j = (j + k) % numsSize;
			}
		}
		break;
	}
	return;
}

int main() {
	int nums[] = { 1,2,3,4,5,6 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	rotate02(nums, numsSize, 4);

	//int a, b;
	//scanf("%d %d", &a, &b);
	//printf("%d,%d的最小公约数为：%d\n", a, b, gcd(a, b));
	//printf("%d,%d的最小公约数为：%d(法二)\n", a, b, gcd2(a, b));
	//printf("%d,%d的最小公倍数为：%d\n", a, b, lcm(a, b));
	return 0;
}