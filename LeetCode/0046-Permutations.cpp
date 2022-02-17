/*
這題直覺用 backtracking
不過看到一個很厲害的方法是用 swap + 遞迴去做
每一層做的事情是從 index 值開始往後做，和其他人交換位置，
然後傳到下一層，直到 index == vector size 為止，就算到底可以回傳了，效率一樣但很酷！
https://leetcode.com/problems/permutations/discuss/18247/My-elegant-recursive-C%2B%2B-solution-with-inline-explanation
*/ 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ans;
        backtracking(nums, ans, cur);
        return ans;
    }
    
    void backtracking(vector<int>& nums, vector<vector<int>>& ans, vector<int>& cur){
        if(nums.empty()){
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            cur.push_back(num);
            nums.erase(nums.begin() + i);
            backtracking(nums, ans, cur);
            nums.insert(nums.begin() + i, num);
            cur.pop_back();
        }
    }
};