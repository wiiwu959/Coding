// 給每個房子中有的錢的 array，不能同時偷相鄰的房子，求偷到總金額的最大值
// Input: nums = [1,2,3,1]
// Output: 4 (1 + 3)

// 用 dp 去紀錄走到每個房子時的最佳選擇，選擇的依據是要不要偷這一家
// 若要這家的錢 + 前前家拿到最好的價值比不偷這一家 (上一家拿到的最好價值) 高，就偷

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        if(nums.size() == 1) { return nums[0]; }
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};