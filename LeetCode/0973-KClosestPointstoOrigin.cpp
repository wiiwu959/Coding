
// O(NlogN): map insert = O(logN)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<float, vector<vector <int>>> record; // distance: [points pair]
        for (int i = 0; i < points.size(); i++) {
            float dist = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            record[dist].push_back(points[i]); 
        }

        int count = 0;
        vector<vector<int>> ans;
        for (auto it = record.begin(); it != record.end() && count < k; it++) {
            for (int i = 0; i < it->second.size() && count < k; i++) {
                ans.push_back(it->second[i]);
                count++;
            }
        }
        return ans;
    }
};