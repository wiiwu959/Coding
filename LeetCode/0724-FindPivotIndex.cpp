// 找到一個中心 index 讓左邊的和 = 右邊的 (這個 index 自己不算)
// Input: nums = [1,7,3,6,5,6]
// Output: 3

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int index = 0;
        int left_sum = 0;
        int right_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            right_sum += nums[i];
        }
        
        for (int i = 0; i < nums.size(); i++) {
            right_sum -= nums[index];
            if (left_sum == right_sum) {
                return index;
            } else {
                left_sum += nums[index++];
            }
        }
        return -1;
    }
};