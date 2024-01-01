// 其實算是腦筋急轉彎...螞蟻互相碰到其實跟單純的擦身而過是一樣的意思
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int max_len = 0;
        for (int& l: left) {
            max_len = max(max_len, l);
        }

        for (int& r: right) {
            max_len = max(n - r, max_len);
        }

        return max_len;
    }
};
