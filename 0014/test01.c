/*
    14. 最长公共前缀
*/
#define MAX_SIZE 200

char *longestCommonPrefix(char **strs, int strsSize)
{
    //当flag=0时匹配结束
    int flag = 1;
    char *ret = (char *)malloc(sizeof(char) * MAX_SIZE);
    int retSize = 0;
    for (int i = 0; flag && i < MAX_SIZE; i++)
    {
        //当前数组匹配结束
        if (strs[0][i] == 0)
            break;
        else
        {
            char tmp = strs[0][i];
            //判断每个数组当前位置是否相同，相同则记入并进入，不同则break并返回
            for (int j = 0; j < strsSize; j++)
            {
                //当前数组匹配结束
                if (strs[j][i] != tmp)
                {
                    flag = 0;
                    break;
                }
            }
            //当前位置各数组相同
            if (flag)
                ret[retSize++] = tmp;
        }
    }
    ret[retSize] = '\0';
    return ret;
}
int main()
{
    int size = 3;
    char *a = "flower";
    char *b = "flow";
    char *c = "flight";
    char **ch = malloc(sizeof(char *) * size);
    ch[0] = a;
    ch[1] = b;
    ch[2] = c;
    longestCommonPrefix(ch, size);
    return 0;
}