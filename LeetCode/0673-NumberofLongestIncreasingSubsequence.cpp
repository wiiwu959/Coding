/*
要找出有有幾個最長的遞增數列
*/

// DP
// 用兩個值來記錄到當前的長度和到這個長度的方式有幾種
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // pair: len / freq (當前的長度 / 到這個長度的組合有幾種)
        vector<pair<int, int>> record(nums.size(), {1, 1});
        int max_len = 1;
        for (int i = 0; i < nums.size(); i++) {
            // 往回檢查
            for (int j = i - 1; j >= 0; j--) {
                // 若這個 j 到這個 i 是遞增的
                if (nums[i] > nums[j]) {
                    // 而且是到目前為止的最長長度
                    if (record[j].first + 1 > record[i].first) {
                        // 更新長度
                        record[i].first = record[j].first + 1;
                        // 更新頻率
                        record[i].second = record[j].second;
                    } else if (record[j].first + 1 == record[i].first) {
                        // 若跟當前到這個位置的最長長度一樣，代表多一種達到這長度的方式
                        record[i].second += record[j].second;
                    }
                }
            }
            max_len = max(max_len, record[i].first);
        }
        
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (record[i].first == max_len) {
                ans += record[i].second;
            }
        }
        return ans;
    }
};