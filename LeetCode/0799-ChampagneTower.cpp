class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> current(1, poured);
        // 要讓香檳從我們的目標 row 流到下一 row 才算完成
        for (int i = 0; i <= query_row; i++) {
            vector<double> next(i + 2, 0);
            for (int j = 0; j < i + 1; j++) {
                // more than one cup
                if (current[j] >= 1) {
                    next[j] += (current[j] - 1) / 2;
                    next[j + 1] += (current[j] - 1) / 2;
                    current[j] = 1;
                }
            }
            if (i != query_row) current = next;
        }
        return current[query_glass];
    }
};
