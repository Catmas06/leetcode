#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
const static string MORSE[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
        "....", "..", ".---", "-.-", ".-..", "--", "-.",
        "---", ".--.", "--.-", ".-.", "...", "-", "..-",
        "...-", ".--", "-..-", "-.--", "--.."
};
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> seen;
        for(string &word: words){
            string buffer = "";
            for(char &ch :word){
                buffer += MORSE[ch-'a'];
            }
            seen.emplace(buffer);
        }
        return seen.size();
    }
};