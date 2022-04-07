/*
    70. 爬楼梯
        假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
        每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
*/
#include <stdio.h>

static int i = 0;

//会超时，递归次数过多
int climbStairs(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == -1)
    {
        return 0;
    }
    if (n == 3)
    {
        printf("%d ", i++);
    }
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main()
{
    printf("\n%d\n", climbStairs(40));
    return 0;
}