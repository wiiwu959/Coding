/*
題目給一堆 pair，這些 pair 最多可以連幾個不重疊 pair
*/

/*
當兩個 pair 沒有重疊的時候，當然沒有問題
但是有重疊時，選擇比較早結束的，好讓下一個 pair 可能的範圍更大一點會更好
所以先以 pair 的結束位置來 sort，然後去 traverse 它

這是 Greedy，O(nlogn)
*/
class Solution {
public:
    static bool compare_pair(vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), compare_pair);
        int cur = pairs[0][1];
        int ans = 1;
        for (int i = 1; i < pairs.size(); i++) {
            if (cur < pairs[i][0]) {
                ans++;
                cur = pairs[i][1];
            }
        }    
        return ans;
    }
};