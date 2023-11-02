class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> record; // record middle num to end
        int last_2 = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            // 因為要先有 3 才會確立 2 這個最大值 (才給 last_2 值)
            // 有了 2 就代表已經有 32 的 pattern 了
            // 最後就是在等一個 1 
            if (nums[i] < last_2) return true;

            while (!record.empty() && nums[i] > record.top()) {
                last_2 = max(record.top(), last_2);
                record.pop();
            }

            record.push(nums[i]);
        }
        return false;
    }
};
