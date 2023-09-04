// __builtin_popcount
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        ans[0] = 0;
        for (int i = 1; i <= n; i++) {
            // 拿掉最後一位有幾個 1  + 最後一位
            ans[i] = ans[i >> 1] + (i % 2);
        }

        return ans;
    }
};