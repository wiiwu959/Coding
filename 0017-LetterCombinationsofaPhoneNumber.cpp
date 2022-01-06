/*
這題練習 Backtracking
Backtracking 的重點就是遇到很多層的問題的時候，
一層一層去解決它，問題進到 function 中就只要做這層的事情
下一層的事情就讓下一次進的 function 處理
然後設好一個停止的點，backtracking 大概就是這麼一回事
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> num_letter = {
            {'2',"abc"}, {'3',"def"}, {'4',"ghi"},
            {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"},
            {'8',"tuv"}, {'9',"wxyz"}
        };
        vector<string> ans;
        string current;
        backtracking(num_letter, current, ans, 0, digits);
        return ans;
    }
    
    void backtracking(map<char, string>& num_letter, string &current, 
                      vector<string>& ans, int now, string digits){
        if(now == digits.size()){
            if(current != "")
                ans.push_back(current);
        }
        else{
            for(int i = 0; i < num_letter[digits[now]].size(); i++){
                current += num_letter[digits[now]][i];
                backtracking(num_letter, current, ans, now + 1, digits);
                current.pop_back();
            }
        }
    }
};