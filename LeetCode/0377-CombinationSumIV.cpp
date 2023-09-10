class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, unsigned long long> dp;
        dp[0] = 1;

        for (int i = 0; i < target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                dp[i + nums[j]] += dp[i];
            }
        }

        return int(dp[target]);
    }
};