// 查看 island 的邊有多長
// 每次遇到陸地就檢查他的四個鄰邊有沒有接到陸地
// 有的話就扣掉那個邊

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int water = 0;
        int stick = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    water++;
                    stick += find_island(grid, i, j);                    
                }
            }
        }
        return (water * 4) - stick;
    }

private:
    int find_island(vector<vector<int>>& grid, int x, int y) {
        int stick = 0;
        if (x - 1 >= 0 && grid[x - 1][y] == 1) {
            stick++;
        }

        if (y - 1 >= 0 && grid[x][y - 1] == 1) {
            stick++;
        }

        if (x + 1 < grid.size() && grid[x + 1][y] == 1) {
            stick++;
        }

        if (y + 1 < grid[0].size() && grid[x][y + 1] == 1) {
            stick++;
        }
        return stick;
    }
};