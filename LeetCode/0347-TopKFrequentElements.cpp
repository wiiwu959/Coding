class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        // map using rbtree, insertion O(logn)
        // O(nlogn)
        for (int& n: nums) {
            freq[n]++;
        }


        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> most_freq;
        // O(nlogn)
        for (auto& a: freq) {
            most_freq.push({a.first, a.second});
        }

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(most_freq.top().first);
            most_freq.pop();
        }
        return ans;
    }
};