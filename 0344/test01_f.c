/*
    344. 反转字符串
    编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
    不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
*/
#include <stdio.h>
#include <malloc.h>

void reverseString(char *s, int sSize)
{
    char *p = s + sSize - 1;
    while (p > s)
    {
        char temp = *p;
        *p = *s;
        *s = temp;
        p--;
        s++;
    }
    return;
}

int main()
{
    int size = 6;
    char s[] = {'h', 'e', 'l', 'l', '0', '0'};
    s[5] = 0;
    reverseString(s, size - 1);
    printf("%s\n", s);
    return 0;
}
