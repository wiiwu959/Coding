/*
input 給一個 array，按照順序從 index 0 開始
prefix 的不重複值數量 - suffix 的不重複值數量
*/

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> ans;
        set<int> prefix;
        set<int> suffix;
        unordered_map<int, int> suffix_num;
        
        for (int i = 0; i < nums.size(); i++) {
            suffix.insert(nums[i]);
            suffix_num[nums[i]] += 1;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            prefix.insert(nums[i]);
            if (--suffix_num[nums[i]] == 0) {
                suffix.erase(nums[i]);
            }
            ans.push_back(prefix.size() - suffix.size());
        }
        
        return ans;
        
    }
};