#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
	122. 买卖股票的最佳时机 II

	给定一个数组 prices ，其中 prices[i] 表示股票第 i 天的价格。
	在每一天，你可能会决定购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以购买它，然后在 同一天 出售。
	返回 你能获得的 最大 利润 。

	-思想
		假设每天都进行操作，从第1天算起。给定的价格从第0天到第priceSize-1天
		若今天的价格比昨天的高，则昨天买入，并将差值计入利润
		若今天的价格 <= 昨天的价格，则昨天不进行买入
*/

int maxProfit(int* price, int priceSize) {
	int maxProfit = 0;
	int D_value = 0;								//记录昨天与今天的价格差值
	for (int i = 1; i < priceSize; i++) {
		D_value = price[i] - price[i - 1];			//初始化差值		
		if (D_value > 0) {							//在昨天买入
			maxProfit += D_value;
		}
	}
	return maxProfit;
}

int main() {
	int price[] = { 7,6,4,3,1 };
	int priceSize = sizeof(price) / sizeof(price[0]);
	printf("利润为：%d\n", maxProfit(price, priceSize));
}