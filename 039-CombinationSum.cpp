/*
寫到這題已經滿熟 backtracking 了
這題又更了解的點是，在寫這裡的時候，
我一開始把 cur.push_back(candidates[i]); 和 cur.pop_back(); 放在if-else 外
然後用 (now + candidates[i] == target) 來做判斷
結果效率差到不行，後來又想想發現把東西送到 function 中時直接拿去判斷會更有效率
結果從 29% -> 89% (60ms -> 8ms)，雖然寫起來很細節但跑起來差很多
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        backtracking(ans, candidates, target, cur, 0, 0);
        return ans;
    }
    
    void backtracking(vector<vector<int>>& ans, vector<int>& candidates,
                      int target, vector<int>& cur, int now, int index){
        for(int i = index; i < candidates.size() && now <= target; i++){
            if(now == target){
                ans.push_back(cur);
                break;
            }
            else{
                cur.push_back(candidates[i]);
                backtracking(ans, candidates, target, cur, now + candidates[i], i);
                cur.pop_back();
            }
        }
    }
};