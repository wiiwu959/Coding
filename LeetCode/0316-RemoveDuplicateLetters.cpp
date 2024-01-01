class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> seen(26, false);
        vector<int> last(26, -1);
        stack<char> ans_stack;

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.size(); i++) {
            if (seen[s[i] - 'a']) continue;
            while (!ans_stack.empty() && s[i] < ans_stack.top() && last[ans_stack.top() - 'a'] > i) {
                seen[ans_stack.top() - 'a'] = false;
                ans_stack.pop();
            }
            ans_stack.push(s[i]);
            seen[s[i] - 'a'] = true;
        }

        string ans = "";
        while (!ans_stack.empty()) {
            ans += ans_stack.top();
            ans_stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
