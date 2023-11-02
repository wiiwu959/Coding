// use stack
class Solution {
public:
    string reverseWords(string s) {
        stack<char> tmp;
        string ans = "";
        for (auto& c: s) {
            if (c == ' ') {
                while (!tmp.empty()) {
                    ans += tmp.top();
                    tmp.pop();
                }
                ans += c;
            } else {
                tmp.push(c);
            }
        }
        while (!tmp.empty()) {
            ans += tmp.top();
            tmp.pop();
        }
        return ans;
    }
};
