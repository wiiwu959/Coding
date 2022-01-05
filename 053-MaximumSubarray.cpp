// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

// 用一個 array 來當前作為終點可以達到的最大值

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        
        vector<int>dp(nums.size(), 0);
        dp[0] = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            if(dp[i - 1] + nums[i] > nums[i]) {
                dp[i] = dp[i - 1] + nums[i];
            }
            else {
                dp[i] = nums[i];
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};