class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> record;
        for (int i = 0; i < nums.size(); i++) {
            record.push(nums[i]);
        }
        
        int ans;
        for (int i = 0; i < k - 1; i++) {
            record.pop();
        }
        return record.top();;
    }
};