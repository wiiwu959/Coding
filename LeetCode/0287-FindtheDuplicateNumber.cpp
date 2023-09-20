/*
找出 array 中重複的那個數字，只會有一個數字重複
array 中的數字範圍只會在 1 ~ array size 之間
*/
// Time: one pass O(n)
// Space: constant O(1)

// use nums[i] as index and set the value in that index as negative if visited.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]);
            if (nums[index] < 0) {
                return index;
            }

            nums[index] = -nums[index];
        }
        return 0;
    }
};
