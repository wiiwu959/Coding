class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> record;
        vector<vector<int>> ans;
        for (int i = 0; i < groupSizes.size(); i++) {
            record[groupSizes[i]].push_back(i);
            if (record[groupSizes[i]].size() == groupSizes[i]) {
                ans.push_back(record[groupSizes[i]]);
                record[groupSizes[i]].clear();
            }
        }
        return ans;
    }
};
