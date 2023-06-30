/*
也是給一個 grid，上下左右有相連的就算是同一個島
找出最大的島

我一樣用 DFS 做，這題跟 200 有點類似
*/


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int island_size = run_down(i, j, grid, 0);
                    if (island_size > max_area) {
                        max_area = island_size;
                    }
                }
            }
        }
        return max_area;
    }

private:
    int run_down(int x, int y, vector<vector<int>>& grid, int island_size) {
        if (x >= grid.size() || y >= grid[0].size() ||
            x < 0 || y < 0) {
                return island_size;
            }
        
        if (grid[x][y] == 0) {
            return island_size;
        }

        island_size++;
        grid[x][y] = 0;
        island_size = run_down(x + 1, y, grid, island_size);
        island_size = run_down(x - 1, y, grid, island_size);
        island_size = run_down(x, y + 1, grid, island_size);
        island_size = run_down(x, y - 1, grid, island_size);

        return island_size;
    }
};