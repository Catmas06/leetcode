/*
    0005.最长回文子串
        二维DP
*/
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2) {
            return s;
        }
        int maxn = 1;
        int begin = 0;
        // 定义了一个vector容器，元素类型为vector<int>，初始化为包含n个vector<int>对象
        // 每个对象都是一个新创立的vector<int>对象的拷贝，而这个新创立的vector<int>对象被初始化为包含n个0。
        // 创建二维dp数组
        vector<vector<bool>> dp(n, vector<bool>(n));
        // 字符本身都是回文串
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        //从回文串长度为2开始统计
        for(int len = 2; len <= n; len++) {
            //枚举左边界
            for(int left = 0; left < n; left++) {
                int right = left + len - 1;
                //该长度下右边界越界
                if(right >= n) {
                    break;
                }
                if(s[left] != s[right]) {
                    dp[left][right] = false;
                }
                else if(left - right < 3 || dp[left+1][right-1]){
                    dp[left][right] = true;
                    //更新保存的最大值
                    if(len > maxn){
                        maxn = len;
                        begin = left;
                    }
                }
                else {
                    dp[left][right] = false;
                }
            }
        }
        return s.substr(begin,maxn);
    }
};