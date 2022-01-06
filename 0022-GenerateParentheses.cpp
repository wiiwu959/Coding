/*
一樣是 Backtracking，做完 017 剛好記憶猶新，
只要注意好停止點就很好寫了。
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        backtracking(cur, ans, n, 0, 0);
        
        return ans;
    }
    
    void backtracking(string& cur, vector<string>& ans, int n, int left, int right){
        if(left == right && left == n){
            ans.push_back(cur);
        }
        
        if(left < n){
            cur += "(";
            backtracking(cur, ans, n, left + 1, right);
            cur.pop_back();
        }
        
        if(right < n && left > right){
            cur += ")";
            backtracking(cur, ans, n, left, right + 1);
            cur.pop_back();
        }
    }
};