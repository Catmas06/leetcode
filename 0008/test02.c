int myAtoi(char *s)
{
    //建立辅助数组，存储有效字符
    char arr[200] = {0};
    //默认符号为+
    int sig = 1, size = 0, flag = 0;
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
    //判断有效字符
    while (*s != 0 && *s != ' ' && *s != '.' && *s != '+' && *s != '-')
    {
        while (flag == 0 && *s == 48)
        {
            s++;
        }
        flag = 1;
        if ((flag && !(*s > 47 && *s < 58)) || size > 10 || *s == 0)
        {
            break;
        }
        if (*s > 47 && *s < 58)
        {
            arr[size++] = *s - '0';
            flag = 1;
        }
        s++;
    }
    //最终输出字符
    if (size != 0)
    {
        for (int i = 0; i < size; i++)
        {
            ret = (ret * 10 + (long)arr[i]);
        }
        if (sig == 1)
        {
            ret = ret > 2147483647 ? 2147483647 : ret;
        }
        else
        {
            ret = -ret < -2147483648 ? -2147483648 : -ret;
        }
        return ret;
    }
    else
        return 0;
}
