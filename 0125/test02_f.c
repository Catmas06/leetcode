/*
    优化
        在原字符串上进行判断，空间复杂度变为O(1)
*/
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *s)
{
    int left = 0, right = strlen(s) - 1;
    while (left < right)
    {
        //修正left与right的位置
        while (left < right && (*(s + left) < 48 || (*(s + left) > 57 && *(s + left) < 65)) || (*(s + left) > 90 && *(s + left) < 97) || *(s + left) > 122)
            left++;
        while (left < right && (*(s + right) < 48 || (*(s + right) > 57 && *(s + right) < 65)) || (*(s + right) > 90 && *(s + right) < 97) || *(s + right) > 122)
            right--;
        if (*(s + left) != *(s + right))
        {
            if (*(s + left) > 64 && *(s + left) < 91)
                *(s + left) += 32;
            if (*(s + right) > 64 && *(s + right) < 91)
                *(s + right) += 32;
            if (*(s + left) != *(s + right))
                return false;
        }
        left++;
        right--;
    }
    return true;
}