/*
    796. 旋转字符串
        给定两个字符串, s 和 goal。如果在若干次旋转操作之后，s 能变成 goal ，那么返回 true 。
        s 的 旋转操作 就是将 s 最左边的字符移动到最右边。
        例如, 若 s = 'abcde'，在旋转一次之后结果就是'bcdea' 。
    思想：
        - 双指针暴力
*/
#include <stdbool.h>
#include <string.h>

bool rotateString(char *s, char *goal)
{
    int size = strlen(s);
    if (strlen(goal) != size)
    {
        return false;
    }
    int i = 0, j = 0;
    int count = 0;
    while (i < size)
    {
        int temp = i;
        while (count < size && *(s + (i % size)) == *(goal + j))
        {
            i++;
            j++;
            count++;
        }
        //失配
        count = 0;
        j = 0;
        i = temp + 1;
    }
    if (i == size)
        return false;
    else
        return true;
}