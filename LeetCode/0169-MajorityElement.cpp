// 找到 array 中超過半數的值

// 用 Boyer–Moore majority vote algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                res = nums[i];
                count++;
                continue;
            }
            
            if (nums[i] == res) {
                count++;
            } else {
                count--;
            }
        }
        return res;
    }
};