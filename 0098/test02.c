#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 0x80000000
#define MIN_SIZE 0x100000000
#define MIN_VAL_2 -2147483649
#define MAX_VAL_2 2147483648

void memory_dump(void *ptr, int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        if (i % 8 == 0 && i != 0)
            printf(" ");
        if (i % 16 == 0 && i != 0)
            printf("\n");
        printf("%02x ", *((unsigned char *)ptr + i));
    }
    printf("\n");
}

int main()
{
    long l1 = (long)MAX_SIZE;
    memory_dump(&l1, sizeof(long));
    long l2 = MIN_SIZE;
    memory_dump(&l2, sizeof(long));
    long l3 = MAX_VAL_2;
    memory_dump(&l3, sizeof(long));
    long l4 = MIN_VAL_2;
    memory_dump(&l4, sizeof(long));
    return 0;
}