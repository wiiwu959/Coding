class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // find the middle
        int middle = 0;
        while (middle < nums.size()) {
            if (nums[middle] >= 0) {
                break;
            }
            middle++;
        }

        vector<int> ans;
        int back = middle - 1;
        while (back >= 0 && middle < nums.size()) {
            if (abs(nums[back]) < abs(nums[middle])) {
                ans.push_back(nums[back] * nums[back]);
                back--;
            } else {
                ans.push_back(nums[middle] * nums[middle]);
                middle++;
            }
        }

        while (back >= 0) {
            ans.push_back(nums[back] * nums[back]);
            back--;
        }

        while (middle < nums.size()) {
            ans.push_back(nums[middle] * nums[middle]);
            middle++;
        }

        return ans;
    }
};

// I see someone using two pointer
// Run from head and tail of the array
// And get the bigger one each time
