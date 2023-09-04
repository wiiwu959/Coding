/*
尋找一個 array 裡連續的數字最長是幾個？
*/

// 練習 union find
// 每次把自己登記成自己的 parent 然漏去檢查前後數字有沒有 parent
// 有 parent 就代表有隸屬的 set 了，就要 union 起來
// 有 O(n)
class Solution {
public:
    unordered_map<int, int> node_parent;
    unordered_map<int, int> parent_size;

    int find_parent(int node) {
        if (node_parent.find(node) == node_parent.end()) {
            node_parent[node] = node;
            return node;
        }

        int parent = node_parent[node];
        while (parent != node_parent[parent]) {
            parent = node_parent[parent];
        }
        return parent;
    }

    void union_set(int a, int b) {
        int i = find_parent(a);
        int j = find_parent(b);
        if (i > j) {
            node_parent[a] = j;
            parent_size[j] += parent_size[i];
            
        } else if (i < j) {
            node_parent[b] = i;
            parent_size[i] += parent_size[j];
        }
    }

    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            // can't find parent, be self parent
            if (node_parent.find(nums[i]) == node_parent.end()) {
                node_parent[nums[i]] = nums[i];
                parent_size[nums[i]] = 1;
            }

            // check previous
            if (node_parent.find(nums[i] - 1) != node_parent.end()) {
                union_set(nums[i], nums[i] - 1);
            }

            // check next
            if (node_parent.find(nums[i] + 1) != node_parent.end()) {
                union_set(nums[i] + 1, nums[i]);
            }
        }
        
        int max = 1;
        for (auto& ps: parent_size) {
            if (ps.second > max) {
                max = ps.second;
            }
        }
        return max;

    }
};

// 簡單又易懂的方法
// 反正就是找到連續數字的開頭 (其中最小的) 然後開始數就對了
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int max_len = 0;
        for (int& num: nums) {
            if (nums_set.count(num - 1) != 0) {
                continue;
            }

            int cur = num;
            while (nums_set.count(cur + 1) != 0) {
                cur = cur + 1;
            }
            max_len = max(cur - num + 1, max_len);
        }
        return max_len;
        
    }
};