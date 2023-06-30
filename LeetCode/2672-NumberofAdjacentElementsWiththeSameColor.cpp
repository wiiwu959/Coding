/*
題目要找每次 query 完有沒有相鄰相同的值
每次 query 都會給一組 index, value 賦值
像是 [2,1,1,1] 就是有 2 組相鄰

我的做法會是每次 query 時都會在賦值前後檢查相鄰的值
*/

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> color(n, 0);
        vector<int> ans;
        int count = 0;
        for (auto& que: queries) {
            int index = que[0];
            int val = que[1];

            // color changed
            if (color[index] != 0 && index > 0 && color[index] == color[index - 1]) {
                count--;
            }

            if (color[index] != 0 && index < n - 1 && color[que[0]] == color[index + 1]) {
                count--;
            }

            color[que[0]] = que[1];

            if (index > 0 && color[index] == color[index - 1]) {
                count++;
            }

            if (index < n - 1 && color[index] == color[index + 1]) {
                count++;
            }

            ans.push_back(count);
        }
        return ans;
    }
};