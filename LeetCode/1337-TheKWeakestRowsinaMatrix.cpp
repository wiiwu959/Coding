class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // num_of_soldier: index
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> weakness;
        for (int i = 0; i < mat.size(); i++) {
            int num = 0;
            for (int& node: mat[i]) {
                if (node == 1) num++;
                else break;
            }
            weakness.push({num, i});
        }

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            pair<int, int> tmp = weakness.top();
            weakness.pop();
            ans.push_back(tmp.second);
        }
        return ans;
    }
};
