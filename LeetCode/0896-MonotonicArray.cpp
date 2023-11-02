class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool decide = false; 
        bool dir = true;// increase
        for (int i = 1; i < nums.size(); i++) {
            if (!decide) {
                if (nums[i - 1] < nums[i]) {
                    decide = true;
                    dir = true;
                } else if (nums[i - 1] > nums[i]) {
                    decide = true;
                    dir = false;
                }
            } else {
                if ((dir && nums[i] < nums[i - 1]) ||
                    (!dir && nums[i] > nums[i - 1])) {
                    return false;
                }
            }
        }
        return true;
    }
};
