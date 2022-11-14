// 看一個 string 裡面有多少個目標的片段，回傳小片段的開頭位置
// s = "cbaebabacd", p = "abc" => [0,6]

// sliding windows
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int window_size = p.length();
        unordered_map<char, int> record;
        vector<int> ans;
        
        // 記錄目標 string 中有哪些 char
        for (int i = 0; i < p.length(); i++) {
            if (record.find(p[i]) == record.end()) {
                record[p[i]] = 0;
            }
            record[p[i]] += 1;
        }
        
        // 找到最開始從 0 算起符合的 string
        int head = 0, tail = 0;
        int count = window_size;
        while (tail < window_size) {
            if (record.find(s[tail]) != record.end()) {
                if (record[s[tail]] > 0) {
                    count--;
                }
                record[s[tail]]--;
            }
            tail++;
        }
        
        while (tail < s.length()) {
            if (count == 0) {
                ans.push_back(head);
            }
            
            if (record.find(s[head]) != record.end()) {
                record[s[head]]++;
                if (record[s[head]] > 0) {
                    count++;
                }
            }
            
            if (record.find(s[tail]) != record.end()) {
                if (record[s[tail]] > 0) {
                    count--;
                }
                record[s[tail]]--;
            }
            tail++;
            head++;
        }
        
        if (count == 0) {
            ans.push_back(head);
        }
        
        return ans;
    }
};

// 因為只會有小寫字母，可以使用 vector 去存
// 而且 vector 間可以直接用 == 比較，應該可以更精簡