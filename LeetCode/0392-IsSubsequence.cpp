// 檢查是不是按照順序的 substring
// Input: s = "abc", t = "ahbgdc"
// Output: true

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;
        int match = 0;
        for (char& c: s) {
            while (index < t.length()) {
                if (c == t[index]) {
                    match++;
                    index++;
                    break;
                }
                index++;
            }
        }
        
        if (match == s.length()) {
            return true;
        }
        return false;
    }
};