/*
每次可以從頭或是從尾拿值，需要最少拿幾個可以加到 x
*/

// Use sliding window
// 先想辦法只從頭拿值滿足條件
// 再從尾端去限縮，取最小值
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int head = -1;
        int tail = nums.size() - 1;

        int ans = -1;
        int acc = 0;
        while (acc < x && head < tail) {
            head++;
            acc += nums[head];
            if (acc == x) {
                ans = head + 1;
            }
        }

        while (head >= 0) {
            acc -= nums[head--];
            while (head < tail && acc < x) {
                acc += nums[tail--];
            }
            if (acc == x) {
                int move = nums.size() - (tail - head);
                if (ans == -1) ans = move;
                else ans = min(ans, move);
            }
        }

        return ans;
    }
};
