/*
給一些區間，然後會插入一個區間
這個插入的區間有可能會跟其他區間重疊，這時候就會合併成同一個區間
*/

// 先處理沒有重疊的，插入前的
// 接著做插入或重疊時的工作
// 最後把剩下的插完
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int cur = 0;

        // before
        while (cur < intervals.size() && intervals[cur][1] < newInterval[0]) {
            ans.push_back(intervals[cur]);
            cur++;
        }

        // during
        // with overlap
        while (cur < intervals.size() && intervals[cur][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[cur][0]);
            newInterval[1] = max(newInterval[1], intervals[cur][1]);
            cur++;
        }
        ans.push_back(newInterval);

        // after
        while (cur < intervals.size()) {
            ans.push_back(intervals[cur]);
            cur++;
        }

        return ans;
    }
};