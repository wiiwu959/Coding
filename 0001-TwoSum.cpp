// 我一開始用的解法，用暴力法解的 --> O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(target == nums[i] + nums[j]) {
                    ans[0] = i;
                    ans[1] = j; 
                    return ans;
                }
            }
        }
        return ans;
    }
};

// 利用 map 來解，只有 O(n) 而已
class Solution2 {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> ans;
            // 第一個放value，第二個放index
            map<int, int> indexMap;
            map<int, int>::iterator iter;

            for(int i = 0; i < nums.size(); i++) {
                iter = indexMap.find(target - nums[i]);
                // 如果有找到，他就是我們要的答案了!
                if(iter != indexMap.end()) {
                    // iter->second就是(target-nums[i])的index
                    ans.push_back(iter->second);
                    ans.push_back(i);
                    return ans;
                }
                // 若是找不到target-num[i]的值就把它放進map裡
                indexMap[nums[i]]=i;
            }

            return ans;
        }
};