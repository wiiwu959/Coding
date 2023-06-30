/*
要照著 右 -> 下 -> 左 -> 上 的方向去轉圈圈排序 2D 的矩陣
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int total = matrix.size() * matrix[0].size();
        
        int upbound = 0;
        int leftbound = 0;
        int downbound = matrix.size() - 1;
        int rightbound = matrix[0].size() - 1;
        
        while (upbound <= downbound && leftbound <= rightbound) {
            // right
            for (int i = leftbound; i <= rightbound; i++) {
                ans.push_back(matrix[upbound][i]);
            }
            upbound++;

            // down
            for (int j = upbound; j <= downbound; j++) {
                ans.push_back(matrix[j][rightbound]);
            }
            rightbound--;
            
            // 最重要的是這個煞車的地方，可以每一次 for 都做
            // 但其實可以在這裡一起檢查
            if (leftbound > rightbound || upbound > downbound) {
                break;
            }
            
            // left
            for (int i = rightbound; i >= leftbound; i--) {
                ans.push_back(matrix[downbound][i]);
            }
            downbound--;
            
            // up
            for (int j = downbound; j >= upbound; j--) {
                ans.push_back(matrix[j][leftbound]);
            }
            leftbound++;
        }

        return ans;
    }
};