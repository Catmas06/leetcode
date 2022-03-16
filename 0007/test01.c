/*
    7.整数反转
        给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
        如果反转后整数超过 32 位的有符号整数的范围，就返回 0。
        假设环境不允许存储 64 位整数（有符号或无符号）。
    思想
        - 先取出x的31位数据，反转后保存在31字节大小的字符数组中
        - 根据符号位进入不同的循环
        - 工作指针指向数组头部，由后向前遍历，每次都将值-‘0’再乘以10累加
        - 累加过程中每次都判断是否越界(累加完后符号不改变)
        - 若工作指针变为-1，则返回累加数字；否则返回0
*/

int reverse(int x)
{
    if (!x)
        return 0;
    //存储x每个十进制字符的数组
    char arr[10] = {0};
    int temp = x;
    int i = 0;
    //找到十进制反向后第一个非0字符
    while (temp && temp % 10 == 0)
    {
        temp /= 10;
    }
    //给arr数组循环赋值
    while (temp)
    {
        arr[i] = temp % 10;
        temp /= 10;
        i++;
    }
    // temp作为累加数组
    temp = 0;
    int j = 0;
    //将j指向反转后第一个非0十进制数字
    while (arr[j] == 0)
    {
        j++;
    }
    //当x是正数
    if (x > 0)
    {
        while (j < i)
        {
            //这一步在计算中会出现溢出，要在溢出前判断而不是溢出后
            temp *= 10;
            temp += ((int)arr[j]);
            if (temp < 0)
            {
                return 0;
            }
            j++;
        }
    }
    //当x为负数
    else
    {
        while (j < i)
        {
            temp *= 10;
            temp += ((int)arr[j]);
            if (temp > 0)
            {
                return 0;
            }
            j++;
        }
    }
    return temp;
}

// int reverse_f(int x);
int main()
{ //-2147483648 <= i <= 2147483647
    int i = 123;
    int j = reverse_f(i);
    return 0;
}