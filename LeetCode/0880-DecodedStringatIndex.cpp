/*
遇到字母就加到當前字串
遇到數字就把當前的字串*數字
*/


// 先算出做完所有行為後的長度
// 再從後面往前去 undo 那些數字的動作直到遇到 k	
class Solution {
public:

    string decodeAtIndex(string s, int k) {
        long long len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                len = len * int(s[i] - '0');
            } else len++;
        }

        string ans = "";
        // come from back, undo multiply until k
        for (int i = s.size() - 1; i >= 0; i--) {
            if (isdigit(s[i])) {
                int digit = int(s[i] - '0');
                len /= digit;
                // if len > k nothing happen
                k %= len;
            } else {
                if (len == k || k == 0) {
                    ans += s[i];
                    break;
                }
                len--;
            }
        }
        return ans;
    }
};
