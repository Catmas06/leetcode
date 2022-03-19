/*
 *	给定一个数字n，输出其对应的外观序列
	注意：
		- ret数组的空间一定给足够多
		- ret数组只能用malloc的方式申请，不能用ret[1000]，否则在ret跳出函数时会释放，导致 heap buffer overflow
		- malloc得来的空间，要么使用 memset初始化，要么在第一次赋值时给予'\0'
 */
#include <string.h>
#include <stdio.h>
#include <malloc.h>

void countAndSay_do(int n, char *ret)
{
	if (n == 1)
	{
		ret[0] = '1';
		ret[1] = '\0';
		return;
	}
	else
	{
		countAndSay_do(n - 1, ret);
		char ch[8000];
		strcpy(ch, ret);
		int size = strlen(ch), retSize = 0;
		for (int i = 0; i < size; i++)
		{
			int count = 1;
			while (i < size - 1 && ch[i] == ch[i + 1])
			{
				count++;
				i++;
			}
			ret[retSize++] = count + '0';
			ret[retSize++] = ch[i];
		}
		ret[retSize] = '\0';
		return;
	}
}

char *countAndSay(int n)
{
	char *ret = (char *)malloc(sizeof(char) * 8000);
	countAndSay_do(n, ret);
	for (int i = 0; ret[i]; i++)
	{
		printf("%c ", ret[i]);
	}
	printf("\n");
	return ret;
}

int main()
{
	char *ret = countAndSay(30);
	for (int i = 0; ret[i]; i++)
	{
		printf("%c ", ret[i]);
	}
	printf("\n");
	return 0;
}