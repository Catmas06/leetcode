/*
    125. 验证回文串
        给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
        说明：本题中，我们将空字符串定义为有效的回文串。
*/
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *s)
{
    //空字符串
    if (!(*s))
        return true;
    // int right = strlen(s) - 1, left = 0;
    //创建辅助数组，仅提取小写字母
    char *ch = (char *)malloc(sizeof(char) * strlen(s));
    int left = 0, right = 0;
    //给right和ch赋初值
    while (*s)
    {
        //大写字母
        if (*s > 64 && *s < 91)
        {
            ch[right++] = *s + 32;
        }
        else if ((*s > 96 && *s < 123) || (*s > 47 && *s < 58))
        {
            ch[right++] = *s;
        }
        s++;
    }
    // flag=0-->不是回文串
    int flag = 1;
    right--;
    while (left < right)
    {
        if (*(ch + left) != *(ch + right))
        {
            flag = 0;
            break;
        }
        left++;
        right--;
    }
    if (flag)
        return true;
    else
        return false;
}