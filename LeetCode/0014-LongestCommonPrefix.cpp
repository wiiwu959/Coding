/*
直接拿第一個字串開始和其他字串一一對比下去，
只要有相同 pre 就保留，沒有就丟掉，全部比完就會是全部都有的共同 prefix 了
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++){
            int j = 0;
            while (j < strs[i].size() && j < prefix.size()){
                if(prefix[j] != strs[i][j]){
                    prefix = prefix.substr(0, j);
                    break;
                }
                j++;
            }
            prefix = prefix.substr(0, j);
        }
        return prefix;
    }
};