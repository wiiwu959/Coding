/*
每一階樓梯可以選擇往上爬 1 階或 2 階
要爬到第 n 階有幾種爬法
*/ 

class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> distinct;
        distinct[0] = 0;
        distinct[1] = 1;
        distinct[2] = 2;

        for (int i = 3; i <= n; i++) {
            distinct[i] = distinct[i - 1] + distinct[i - 2];
        }

        return distinct[n];
    }
};