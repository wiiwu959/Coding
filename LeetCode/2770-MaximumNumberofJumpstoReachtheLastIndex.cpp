/* 
每次從一個 index 跳到另外一格，要符合兩者差小於 target 才行
算到達終點可以最多跳幾下
*/

// 用 DP 去記錄從 0 跳到各個位子的最大跳躍數，每一個數字都會往前檢查
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> jumps(nums.size(), 0); // from 0 to index n
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (abs(nums[i] - nums[j]) <= target) {
                    if (j != 0 && jumps[j] == 0) {
                        continue;
                    }
                    jumps[i] = max(jumps[j] + 1, jumps[i]);
                }
            }
        }
        if (jumps[nums.size() - 1] == 0) {
            return -1;
        }
        return jumps[nums.size() - 1];
    }
};