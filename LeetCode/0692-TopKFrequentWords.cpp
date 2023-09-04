// 找到 Top k 常出現的單詞，照字母順序排

// Top k 都可以用到 Heap sort 去處理，priority queue 就是用 heap sort 做的
// 這裡因為是以 pair: word-freq 的方式儲存的，所以我自己寫了個 operator O(nlogk)
class Solution {
public:
    struct cmp {
        bool operator()(pair<string, int> a, pair<string, int> b) {
            if (a.second < b.second) {
                return true;
            }
            
            if (a.second == b.second) {
                int len = min(a.first.size(), b.first.size());
                for (int i = 0; i < len; i++) {
                    if (a.first[i] != b.first[i]) {
                        if (a.first[i] > b.first[i]) return true;
                        else return false;
                    }
                }
            }

            return false;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map <string, int> freq;
        for (string& word: words) {
            freq[word]++;
        }

        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> record;
        for (auto& data: freq) {
            record.push({data.first, data.second});
        }

        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(record.top().first);
            record.pop();
        }
        return ans;
    }
};