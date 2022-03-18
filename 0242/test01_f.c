/*
    242. 有效的字母异位词
        给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
        注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
    思想
        - 用两个数组分别统计s,t中各字符出现次数
        - 最后遍历辅助数组，不相等则匹配失败，否则匹配成功
    优化思路
        - 仅维护一个数组，第一次添加，第二次删除，最后看数组是否全0
*/
#include <stdbool.h>

bool isAnagram(char *s, char *t)
{
    int arr1[26] = {0};
    int arr2[26] = {0};
    //辅助变量，计数
    int count = 0;
    //统计s内字符
    while (*s)
    {
        arr1[*s - 'a' - 1]++;
        s++;
    }
    //统计t内字符
    while (*t)
    {
        arr2[*s - 'a' - 1]++;
        t++;
    }
    //判断是否相等
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] == arr2[i])
            continue;
        else
            return false;
    }
    return true;
}