class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        // use priority queue from small to big
        // So we can reach smallest effort to end first
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;

        dist[0][0] = 0;
        // {effort to the point, x, y}
        minHeap.push({0, {0, 0}});

        while (!minHeap.empty()) {
            pair<int, pair<int, int>> current = minHeap.top();
            minHeap.pop();

            int effort = current.first;
            int x = current.second.first;
            int y = current.second.second;
        
            // if effort from current point to this point is larger than other point to this point
            // We don't need to consider this point
            if (effort > dist[x][y]) continue;
            // Because we use priority queue, 
            // When found reach the end, finish the process
            if (x == heights.size() - 1 && y == heights[0].size() - 1) {
                return effort;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + direction[i][0];
                int ny = y + direction[i][1];

                // in the range
                if (nx >= 0 && ny >= 0 && nx < heights.size() && ny < heights[0].size()) {
                    // effort of (nx, ny)
                    // 抵達 (x, y) 的最大差 (=effort) 跟 (x, y) 到 (nx, ny) 相比
                    int newEffort = max(effort, abs(heights[nx][ny] - heights[x][y]));
                    // if current effort to this point is less than previous least effort
                    // renew the least effort to this one and consider this point as the path
                    if (newEffort < dist[nx][ny]) {
                        dist[nx][ny] = newEffort;
                        minHeap.push({newEffort, {nx, ny}});
                    }
                }
            }
        }
        return -1;
    }
};
