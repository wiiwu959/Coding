// 偵測 # 為按下 backspace
// 看看兩個 string 是不是一樣

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> typing1, typing2;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#') {
                if (!typing1.empty()) {
                    typing1.pop();
                }
            } else {
                typing1.push(s[i]);
            }
        }
        
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == '#') {
                if (!typing2.empty()) {
                    typing2.pop();
                }
            } else {
                typing2.push(t[i]);
            }
        }
        
        if (typing1.size() != typing2.size()) {
            return false;
        }
        
        while (!typing1.empty() && !typing2.empty()) {
            if (typing1.top() != typing2.top()) {
                return false;
            }
            typing1.pop();
            typing2.pop();
        }
        
        if (!typing1.empty() || !typing2.empty()) {
            return false;
        }
        return true;
        
    }
};