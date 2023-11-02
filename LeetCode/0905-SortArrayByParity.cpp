class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int head = 0;
        int tail = nums.size() - 1;

        while (head < tail) {
            if (nums[head] % 2 == 1 && nums[tail] % 2 == 0) {
                int tmp = nums[head];
                nums[head] = nums[tail];
                nums[tail] = tmp;
                head++; tail--;
            } else if (nums[head] % 2 == 0) {
                head++;
            } else if (nums[tail] % 2 == 1) {
                tail--;
            }
        }
        return nums;
    }
};
