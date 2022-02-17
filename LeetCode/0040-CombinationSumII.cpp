/*
這一題和上一題是同一個系列的，不過這題規定不能用重複的數字來湊
所以一開始先做 sorting 後，再加上一些不同上一題的條件判斷即可
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, ans, cur, 0, 0);
        return ans;
    }
    
    void backtracking(vector<int>& candidates, int target, vector<vector<int>>& ans,
                      vector<int>& cur, int now, int index){
        for(int i = index; i <= candidates.size() && now <= target; i++){
            if(now == target){
                ans.push_back(cur);
                break;
            }
            if(i < candidates.size()){
                if(i > index && candidates[i] == candidates[i - 1]){ continue; }
                cur.push_back(candidates[i]);
                // 這裡傳到下一次 function 的 index 要 + 1 避免重複用到
                backtracking(candidates, target, ans, cur, now + candidates[i], i + 1);
                cur.pop_back();
            }
        }
    }
};