#include <math.h>
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(!n) {
            return false;
        }
        int x = (int)(log2(n) / log2(3) + 1e-1);
        return fabs(n - pow(3, x)) < 1e-1;
    }
};