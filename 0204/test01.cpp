/*
    count primes
        - 仅搜索根号x
        $ 埃及筛
        - 线性筛
*/

#include <malloc.h>
#include <string.h>
#include <vector>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if(n < 2) {
            return 0;
        }
        int* map = (int*)malloc(sizeof(int) * n);
        memset(map, 0, sizeof(int) * n);
        for(int i = 2; i < n; i++) {
            //找到下标不为0的值并记录、更新后值
            while(i < n && map[i] != 0) {
                i++;
            }
            if(i >= n) {
                break;
            }
            map[0] += 1;
            //更新后值
            for(int j = 2; j * i * i * j < n; j++) {
                map[j * i] = 1;
            }
        }
        int ret = map[0];
        free(map);
        return ret;
    }
};