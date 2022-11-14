// 給兩個 string 把第一個 string 的字母做替換能否變第二個 string (必須一對一 mapping)

// Input: s = "egg", t = "add"
// Output: true
// Input: s = "foo", t = "bar"
// Output: false

// 要特別注意 "badc" "baba" 的 case
// 這種就是沒有一對一 map 的情況

// Using two map (用 array 更快)
// time: O(n) (n = s.length())
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s2t[127] = {0};
        int t2s[127] = {0};
        for (int i = 0; i < s.size(); i++) {
            if (s2t[(int)s[i]] == 0) {
                s2t[(int)s[i]] = (int)t[i];
            } else {
                if (char(s2t[(int)s[i]]) != t[i]) {
                    return false;
                }
            }
            
            if (t2s[(int)t[i]] == 0) {
                t2s[(int)t[i]] = (int)s[i];
            } else {
                if (char(t2s[(int)t[i]]) != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};