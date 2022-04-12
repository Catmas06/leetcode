/*
    326. 3 的幂
*/

class solution{
public:
    bool isPowerOfThree(int n) {
        if(n % 3 == 0){
            n /= 3;
        }
        if(n == 1){
            return true;
        }
        return false;
    }
};