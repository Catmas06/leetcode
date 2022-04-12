/*
    0005.最长回文子串
        中心扩散法
            - 枚举所有的中心点
            - 从中心点开始向外扩散，看是否满足回文子串
            - 取得当前子串长度与历史最大长度的较大值
            - 枚举结束后返回历史最大值
        时间复杂度 O(n^2)
        空间      O(1)
*/

#include <string>
#include <vector>
#define MAX(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

class Solution {
private:
    int diffusion(string& s, int left, int right) {
        int size = s.size();
        int retLen = left == right ? 0 : 1;
        while(left >= 0 && right < size - 1) {
            if(s[left] != s[right]) {
                break;
            }
            else {
                retLen += 2;
            }
        }
        return retLen;
        left--;
        right++;
    }

public:
    string longestPalindrome(string s) {
        // 枚举所有中心点
        int size = s.size();
        if(size < 2) {
            return s;
        }
        int maxLen = 1;
        int begin = 0;
        //判断特例
        if(s[0] == s[1]){
            maxLen = 2;
            begin = 0;
        }
        int maxLen = 1;
        int begin = 0;
        // 边界点 0 与 size-1 不用作为中心点
        for(int i = 1; i < size - 1; i++) {
            int oddLen = diffusion(s, i, i);
            int evenLen = diffusion(s, i, i + 1);
            int tmp = MAX(oddLen, evenLen);
            // 更新历史最大值
            if(tmp > maxLen) {
                maxLen = tmp;
                begin = i - (maxLen - 1) / 2;
            }
        }
        return s.substr(begin, maxLen);
    }
};