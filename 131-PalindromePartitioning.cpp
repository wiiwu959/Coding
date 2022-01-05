/*
題目要把一個字串的裡面所有不同回文組合印出來
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

所以就是結合 DFS + 找字串中的回文
找回文可以參照 005 用 DP 做，用 dp[i][j] 代表從 i 到 j 這段是不是回文
然後列出所有組合就可以用 DFS 做
每次只處理一段裡面的組合
*/


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> isPan(s.length() + 1, vector<bool>(s.length() + 1, false));
        for(int i = s.length() - 1; i >= 0; i--) {
            for(int j = i; j < s.length(); j++) {
                if(s[i] == s[j] && (j - i < 3 || isPan[i + 1][j - 1])) {
                    isPan[i][j] = true;
                }
            }
        }

        vector<vector<string>> ans;
        vector<string> current;
        backtrack(s, isPan, 0, current, ans);
        
        return ans;
    }
    
    void backtrack(string s,vector<vector<bool>>& isPan,
                    int from, vector<string>& current, vector<vector<string>>& ans)
    {
        if(from == s.length()) { 
            ans.push_back(current);
            return;
        }
        
        for(int i = from; i < s.length(); i++)
        {
            if(isPan[from][i])
            {
                current.push_back(s.substr(from, i - from + 1));
                backtrack(s, isPan, i + 1, current, ans);
                current.pop_back();
            }
        }
    }
    
};