// 背包問題，兔子教過我的，去翻筆記
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> loc_num(amount + 1, 0); // location, used_num;
        for (int i = 0; i <= amount; i++) {
            if (i == 0 || loc_num[i] != 0) {
                for (long coin: coins) {
                    if (i + coin > amount) continue;
                    if (loc_num[i + coin] != 0) {
                        loc_num[i + coin] = min(loc_num[i + coin], loc_num[i] + 1);
                    } else {
                        loc_num[i + coin] = loc_num[i] + 1;
                    }
                }
            }
        }
        
        if (loc_num[amount] == 0) {
            return -1;
        }
        return loc_num[amount];
    }
};