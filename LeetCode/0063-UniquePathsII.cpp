// 跟 062 一樣不過多了障礙物，所以一開始他就給障礙物的二維陣列了

// 因為不想再額外開空間，想直接利用原本的陣列
// 所以多了一些檢查，不過概念上還是跟 062 一樣

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1) { return 0;}

        int now = -1;
        for(int i = 0; i < m; i++) {
            if(obstacleGrid[i][0] == 1) { now = 0; };
            obstacleGrid[i][0] = now;
        }

        now = -1;
        for(int i = 0; i < n; i++) {
            if(obstacleGrid[0][i] == 1) { now = 0; };
            obstacleGrid[0][i] = now;
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1) { 
                    obstacleGrid[i][j] = 0; 
                }
                else {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1]; 
                }
            }
        }

        return -obstacleGrid[m - 1][n - 1];
    }
};