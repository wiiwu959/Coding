/*
可以從每個 index 選擇走一步或兩步，會花費 cost[index]
要找出到達終點的最小 cost
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int target = cost.size();
        vector<int> record(target + 1, 0);

        for (int i = 2; i <= target; i++) {
            record[i] = min(record[i - 1] + cost[i - 1], record[i - 2] + cost[i - 2]);
        }

        return record[target];
    }
};