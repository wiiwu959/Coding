/*
一樣是小島，要找到離陸地最遠的水的距離值
這題最好的做法是掃兩次，從左上開始一次，右下開始一次
*/

// 這題應該要用 BFS 做
// 每次成功更新的距離就加到 queue 裡面，一層一層做
class Solution {
public:
    struct coordinate {
        int x;
        int y;
    };

    queue<coordinate> to_go;

    int maxDistance(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    to_go.push({i, j});
                }
            }
        }

        int max_dis = 0;
        while(!to_go.empty()) {
            coordinate temp = to_go.front();
            to_go.pop();

            int dis = grid[temp.x][temp.y];
            add_dis(temp.x + 1, temp.y, dis + 1, grid);
            add_dis(temp.x - 1, temp.y, dis + 1, grid);
            add_dis(temp.x, temp.y + 1, dis + 1, grid);
            add_dis(temp.x, temp.y - 1, dis + 1, grid);
            if (dis - 1 > max_dis) {
                max_dis = dis - 1;
            }
        }

        if (max_dis == 0) {
            return -1;
        }

        return max_dis;

    }

private:
    void add_dis(int x, int y, int dis, vector<vector<int>>& grid) {
        if (x < 0 || x >= grid.size() ||
            y < 0 || y >= grid[0].size()) {
            return;
        }
        if (grid[x][y] != 0) {
            return;
        }
        grid[x][y] = dis;
        to_go.push({x, y});
    }
};

// 這是用 DFS 去從每個陸地往外找，直到碰到陸地
// 雖然應該是對的，但是會 TLE
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int max_dis = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    find_island(i, j, grid, 1, true);
                }
            }
        }

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] - 1 > max_dis) {
                    max_dis = grid[i][j] - 1;
                }
            }
        }
        
        if (max_dis == 0) {
            return -1;
        }
        
        return max_dis;
    }

private:
    void find_island(int x, int y, vector<vector<int>>& grid, int dis, bool start) {
        if (x < 0 || x >= grid.size() ||
            y < 0 || y >= grid[0].size()) {
                return;
            }

        if (grid[x][y] == 1) {
            if (!start) {
                return;
            }
        } else if (grid[x][y] == 0) {
            grid[x][y] = dis + 1;
        } else if (grid[x][y] > dis + 1) {
            grid[x][y] = dis + 1;
        } else {
            return;
        }

        find_island(x + 1, y, grid, grid[x][y], false);
        find_island(x - 1, y, grid, grid[x][y], false);
        find_island(x, y + 1, grid, grid[x][y], false);
        find_island(x, y - 1, grid, grid[x][y], false);

        return;
    }
};


// 這個掃兩次的方法有點 Dynamic Programming ?
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) { continue; }
                if (i + 1 < grid.size() && grid[i + 1][j] != 1) {
                    if (grid[i + 1][j] == 0 || grid[i + 1][j] > grid[i][j] + 1) {
                        grid[i + 1][j] = grid[i][j] + 1;
                    }
                }

                if (j + 1 < grid[0].size() && grid[i][j + 1] != 1) {
                    if (grid[i][j + 1] == 0 || grid[i][j + 1] > grid[i][j] + 1) {
                        grid[i][j + 1] = grid[i][j] + 1;
                    }
                }
            }
        }

        int max_dis = 0;
        for(int i = grid.size() - 1; i >= 0; i--) {
            for(int j = grid[0].size() - 1; j >= 0; j--) {
                if (grid[i][j] == 0) { continue; }
                if (i - 1 >= 0 && grid[i - 1][j] != 1) {
                    if (grid[i][j] + 1 < grid[i - 1][j] || grid[i - 1][j] == 0) {
                        grid[i - 1][j] = grid[i][j] + 1;
                    }
                }

                if (j - 1 >= 0 && grid[i][j - 1] != 1) {
                    if (grid[i][j] + 1 < grid[i][j - 1] || grid[i][j - 1] == 0) {
                        grid[i][j - 1] = grid[i][j] + 1;
                    }
                }
                
                if (grid[i][j] > max_dis) {
                    max_dis = grid[i][j];
                }
            }
        }

        if (max_dis == 0 || max_dis == 1) {
            return -1;
        }

        return max_dis - 1;
    }
};