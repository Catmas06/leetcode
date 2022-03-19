/*
    KMP算法
        next[i]表示：若模式串第i个元素失配，则用模式串的第next[i]个元素与主串比较，重复进行，直至元素匹配成功或为0
        模式串与主串都向后移动一位，重复进行，直至串尾
        若模式串遍历完毕，匹配成功；否则匹配失败

    next数组求法
        next[0] = -1;   --> 表示当前的主串与模式串都要后移
        next[1] = 0;    --> 表示当前的主串应与模式串首元素进行比较
        next[i] = k;    --> 若模式串第i个元素与主串失配，则用模式串第k个元素与主串继续匹配，并重复

        可再将模式串视为两个，一个主串一个模式串。主串的指针i不回溯，模式串指针为j
        假设 next[i]=j 已知,则模式串中前面的j个元素都与主串有匹配，
        若当前两元素匹配，则当前模式串与主串指针都向后移动一位，
        否则，j向前回溯到 next[j],重复与i匹配
        当j变为-1时，表明当前模式串没有元素能与主串匹配，则两个串的指针都后移一位

    - 数组下标从0开始，即元素从第0个开始
    - 在主串中寻找模式串 (在 hello 中寻找 ll)
*/
#include <stdlib.h>
#include <string.h>
int KMP(char *haystack, char *needle)
{
    //模式串为NULL
    if (!*needle)
        return 0;
    //求模式串的next数组
    int strlen_haystack = strlen(haystack);
    int strlen_needle = strlen(needle);
    //为next数组分配空间
    int *next = (int *)malloc(sizeof(int) * strlen_needle);
    int i = 0, j = -1;
    next[0] = -1;
    while (i < strlen_needle - 1)
    {
        if (j == -1 || needle[i] == needle[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
    //与主串匹配
    i = 0;
    j = 0;
    while (i < strlen_haystack && j < strlen_needle)
    {
        if (j == -1 || haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == strlen_needle)
        return i - strlen_needle;
    else
        return -1;
}

int main()
{
    KMP("hello", "ll");
    return 0;
}