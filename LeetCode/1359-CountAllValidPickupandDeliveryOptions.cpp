class Solution {
public:
    int countOrders(int n) {
        vector<long long> ans(2, 1);
        int cum = 6;
        for (int i = 2; i <= n; i++) {
            ans.push_back(ans[i - 1] * cum % (1000000007));
            cum += (i * 2 + 1) * 2 - 1;
        }

        return int(ans[n] % (1000000007));
    }
};
