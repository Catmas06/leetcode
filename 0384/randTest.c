#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n = 100;
    srand((unsigned)time(NULL));
    int i = rand() % n;
    int j = rand() % n;
    printf("i=%d j=%d\n", i, j);
    // srand((unsigned)time(NULL));
    i = rand() % n;
    j = rand() % n;
    printf("i=%d j=%d\n", i, j);
    // srand((unsigned)time(NULL));
    i = rand() % n;
    j = rand() % n;
    printf("i=%d j=%d\n", i, j);
    // srand((unsigned)time(NULL));
    i = rand() % n;
    j = rand() % n;
    printf("i=%d j=%d\n", i, j);
    return 0;
}