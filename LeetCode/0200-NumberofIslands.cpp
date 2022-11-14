// 找總共有幾個 island (周圍都是 '0' 的 '1')
// 用 DFS 每次標註一個新的島就把周圍有碰到的 (同一座島的) 改成 '0'

class Solution {
public:
    void DFS(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return;
        }

        if (grid[i][j] == '1') {
            grid[i][j] = '0';
            DFS(i + 1, j, grid);
            DFS(i - 1, j, grid);
            DFS(i, j + 1, grid);
            DFS(i, j - 1, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int max_island = 0;
        vector<vector<int>> island(grid.size(),vector<int>(grid[0].size(), -1));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    DFS(i, j, grid);
                    max_island++;
                }
            }
        }
        return max_island;
    }
};