/*
和 046 幾乎一樣，只多加了 sort 和判斷有沒有重複的一個句子而已
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        backtracking(nums, ans, cur);
        return ans;
    }
    
    void backtracking(vector<int>& nums, vector<vector<int>>& ans, vector<int>& cur){
        if(nums.empty()){
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i - 1] == nums[i]) { continue; }
            
            int num = nums[i];
            cur.push_back(num);
            nums.erase(nums.begin() + i);
            backtracking(nums, ans, cur);
            nums.insert(nums.begin() + i, num);
            cur.pop_back();
        }
    }
};