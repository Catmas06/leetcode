#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
int myAtoi(char *s)
{
    //默认符号为+
    int sig = 1;
    long ret = 0;
    //过滤空格
    while (*s && *s == ' ')
        s++;
    //判断符号，默认为+
    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            sig = -1;
        s++;
    }
    //过滤开头0
    while (*s == '0')
    {
        s++;
    }
    while (isdigit(*s))
    {
        ret = (ret * 10 + (*s - '0'));
        if (ret > INT_MAX)
        {
            return sig > 0 ? INT_MAX : INT_MIN;
        }
        s++;
    }
    return sig > 0 ? ret : -ret;
}