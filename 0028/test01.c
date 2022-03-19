/*
    28. 实现 strStr()
*/
#include <string.h>
#include <stdio.h>
int strStr(char *haystack, char *needle)
{
    if (*needle == 0)
        return 0;
    int ret = 0, ph = 0, pn = 0;
    int strlen_h = (int)strlen(haystack);
    int strlen_n = (int)strlen(needle);
    while (ph <= strlen_h - strlen_n)
    {
        while (pn < strlen_n)
        {
            if (*(haystack + ph) != *(needle + pn))
                break;
            ph++;
            pn++;
        }
        if (pn == strlen(needle))
            return ret;
        ret++;
        ph = ret;
        pn = 0;
    }
    return -1;
}
