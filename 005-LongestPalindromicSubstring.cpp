// 練習用dynamic programming
// 如果頭尾相同，中間的東西又是palindromic的話，這個字串就也是
// 所以可以利用這點把之間的結果存起來
// 若是位置i到j的這段字串是回文，那isPalin[i][j]就=true
class Solution {
public:
    string longestPalindrome(string s) {
        bool** isPalin = new bool*[s.size()];
        for(int i = 0; i < s.size(); i++){
            isPalin[i] = new bool[s.size()];
        }
        int l = s.size();
        string maxString = "";

        for(int i = l ; i >= 0; i--){
            for (int j = i; j < l; j++){
                if(s[i] == s[j] && (j - i < 3 || isPalin[i+1][j-1])){
                    isPalin[i][j] = true;
                    if(j - i + 1 > maxString.size()){
                        maxString = s.substr(i, j - i + 1);
                    }
                }
                else {
                    isPalin[i][j] = false;
                }
            }
        }
        return maxString;
    }
};