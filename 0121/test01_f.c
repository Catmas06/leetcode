/*
    121. 买卖股票的最佳时机
        给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
        你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
        返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
*/
#include <math.h>

int maxProfit(int *prices, int pricesSize)
{
    int curProfit = 0, maxProfit = 0;
    int minPrice = prices[0], day = 1;
    while (day < pricesSize)
    {
        //如果盈利，则将今天的盈利与历史最大盈利比较，并记录最大值
        if (prices[day] > minPrice)
        {
            maxProfit = fmax(prices[day] - minPrice, maxProfit);
        }
        //未盈利，则查看当前价格是否低于历史最小，是则更新最小值，否则不变
        else if (prices[day] < minPrice)
        {
            minPrice = prices[day];
        }
        day++;
    }
    return maxProfit;
}