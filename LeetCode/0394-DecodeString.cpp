// 題目要把有中括號 ([]) 的 string 展開
// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef" 

// 基本上就是把條件設好，我用一個 stack 去紀錄括號的數量
// 然後用 recursive 去處理內層的內容
class Solution {
public:
    string decodeString(string s) {
        string num, str, ans;
        stack<char> brace_st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ']') {
                brace_st.pop();
                if (brace_st.empty()) {
                    string target = decodeString(str);
                    int mul = stoi(num);
                    for (int time = 0; time < mul; time++) {
                        ans += target;
                    }

                    // set all varible back
                    num = "";
                    str = "";
                } else {
                    str += s[i];
                }
            } else if (!brace_st.empty()) {
                str += s[i];
                if (s[i] == '[') {
                    brace_st.push(s[i]);
                }
            } else if (s[i] == '[') {
                brace_st.push(s[i]);
            } else if (int(s[i]) >= '0' && int(s[i]) <= '9') {
                num += s[i];
            } else {
                ans += s[i];
            }
        }
        
        return ans;
    }
};