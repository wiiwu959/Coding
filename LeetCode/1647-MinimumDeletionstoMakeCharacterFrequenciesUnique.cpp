class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        int ans = 0;
        unordered_map<int, bool> record;
        for (int i = 0; i < 26; i++) {
            // there is same freq
            while (record.find(freq[i]) != record.end() && freq[i] != 0) {
                ans++;
                freq[i]--;
            }
            
            record[freq[i]] = true;
        }

        return ans;   
    }
};
