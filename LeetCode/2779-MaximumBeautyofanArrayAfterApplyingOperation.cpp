/*
可以把 array 裡的數字換成 nums[i] + k 或 nums[i] - k
找出最多可以有幾個一樣的數字
*/

// 把每個數字的範圍標起來，same_time 的 key: val 對應著從 key 這個位置開始往下到下一個 key 這範圍的重疊數量變化為 val
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int, int> same_time;
        unorder_map<int, int> add;
        for (int i = 0; i < nums.size(); i++) {
            same_time[nums[i] - k]++;
            add[nums[i] - k]++;
            same_time[nums[i] + k]--;
        }
        
        int cur = 0;
        int ans = 0;
        for (map<int, int>::iterator it = same_time.begin(); it != same_time.end(); it++) {
            ans = max(cur + add[it->first], ans);
            cur += it->second;
            ans = max(cur, ans);
        }
        return ans;
    }
};