// 題目是要找出一串字的所有 subsets
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// 用 backtracking，找回手感了!!
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        vector<int> current;
        backtracking(nums, ans, 0, current);
        return ans;
    }

    
    void backtracking(vector<int>& nums, vector<vector<int>>& ans, int index, vector<int>& current) {

        if(index == nums.size()) { return; }
        
        for(int i = index; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtracking(nums, ans, i + 1, current);
            ans.push_back(current);
            current.pop_back();
        }
    }
};