#include <math.h>
#include <stdio.h>
int main() {
    double x = log2(45) / log2(3);
    double y = pow(3, x);
    int z = (int)x;
    printf("%f\n", y);
    return 0;
}