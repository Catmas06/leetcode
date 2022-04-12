/*
    埃及筛的优化
        - 更新标记从 x^2 处开始，因为 x^2 之前的数字一定被标记过了
        - 是使用bool数组来存储数据
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
        bool* map = (bool*)malloc(sizeof(bool) * n);
        memset(map, 0, sizeof(bool) * n);
        int ans = 0;
        for(int i = 2; i < n; i++) {
            //找到下标不为0的值并记录、更新后值
            while(i < n && map[i]) {
                i++;
            }
            if(i >= n) {
                break;
            }
            ans++;
            //更新后值
            for(int j = 0; (long long)i * (i + j) < n; j++) {
                map[i * (i + j)] = 1;
            }
        }
        free(map);
        return ans;
    }
};