/*
    387. 字符串中的第一个唯一字符
        给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
    思想
        - s只有小写字母
        - 创建大小为26的数组，用以记录是否已存在相同元素,第一次出现则记录其下标，再次出现则改值为-1
        - 创建标志count --> 26 全部重复
*/

int firstUniqChar(char *s)
{
    int arr[27];
    int i = 0, temp = 0;
    while (i < 27)
    {
        arr[i++] = -1;
    }
    i = 0;
    //当下标指向'\0'时完成遍历
    while (*(s + i))
    {
        //当前下标已出现过
        if (arr[*(s + i) - 'a'] != -1)
        {
            arr[*(s + i) - 'a'] = -2;
        }
        else
        {
            arr[*(s + i) - 'a'] = i;
            temp++;
            if (temp > 26)
                return -1;
        }
        i++;
    }
    i = 0;
    temp = 100000;
    while (i < 26)
    {
        //字母出现过
        if (arr[i] != -1 && arr[i] != -2)
        {
            if (temp > arr[i])
                temp = arr[i];
        }
        i++;
    }
    if (temp == 100000)
        return -1;
    else
        return temp;
}

int main()
{
    char *s = "itwqbtcdprfsuprkrjkausiterybzncbmdvkgljxuekizvaivszowqtmrttiihervpncztuoljftlxybpgwnjb";
    firstUniqChar(s);
    return 0;
}