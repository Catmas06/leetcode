/*
    -2147483648 <= ret <= 2147483647
    合法取值应在[-2147483648,2147483647]
    若 ret < -214748364.8 则在 ret*10后溢出
    若 ret > 214748364.7 则在 ret*10后溢出
    ret 最后一位由 x 第一位决定，x 第一位最大为2，则以上结果取相等时不会溢出
*/
#include <stdio.h>

int reverse(int x)
{
    if (!x)
        return 0;
    int ret = 0;
    //去掉十进制反转后开头的0
    while (x % 10 == 0)
    {
        x /= 10;
    }
    while (x)
    {
        //判断本次赋值是否可能溢出
        if (ret < -214748364 || ret > 214748364)
            return 0;
        ret = ret * 10 + x % 10;
        x /= 10;
    }
    //无异常则完成反转
    return ret;
}

// int reverse_f(int x);
int main()
{ //-2147483648 <= i <= 2147483647
    int i;
    scanf("%d", &i);
    int j = reverse(i);
    printf("输入为%d,反转后为%d\n", i, j);
    return 0;
}