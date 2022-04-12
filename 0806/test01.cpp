#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int size = s.size();
        int line = 1;
        int count = 1;
        for(int i = 0; i < size; i++) {
            count = 0;
            while(i < size && count <= 100) {
                count += widths[s[i] - 'a'];
                i++;
            }
            // 回溯
            if(count > 100) {
                i--;
                line += 1;
                count -= widths[s[i] - 'a'];
            }
        }
        return { line, count };
    }
};