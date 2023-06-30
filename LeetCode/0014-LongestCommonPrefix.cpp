/*
直接拿第一個字串開始和其他字串一一對比下去，
只要有相同 pre 就保留，沒有就丟掉，全部比完就會是全部都有的共同 prefix 了
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for (string& s: strs) {
            int len = prefix.length();
           
            for (int i = 0; i < len; i++) {
                if (prefix[i] != s[i]) {
                    prefix = prefix.substr(0, i);
                }
            }
        }
        return prefix;
    }
};