// 題目要找插入點，要求 O(logn)
// ex. Input: nums = [1,3,5,6], target = 5 -> Output: 2

// Binary search

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid = 0, head = 0;
        int tail = nums.size() - 1;
        
        while(head <= tail)
        {
            mid = head + (tail - head) / 2;
            if(nums[mid] < target) {
                head = mid + 1;
            }
            else {
                tail = mid - 1;
            }
        }
        return head;
    }
};