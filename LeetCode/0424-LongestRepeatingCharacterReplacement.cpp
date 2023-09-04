/*
要找出一個 string 若是可以替換掉最多 k 個字
可以組成多長的連續字母串
*/

// sliding window
// 一開始我有點執著要記錄每次當前最長的字母是什麼
// 但後來發現我只要知道出現頻率最多的那個 "頻率" 就夠了
// 用這個最高頻剪去整個字串長度就可以知道需要替換多少字了
class Solution {
public:
    int characterReplacement(string s, int k) {
        int head = 0;
        int tail = 0;

        vector<int> freq(26, 0);
        int most = 0;
        int ans = 0;
        while (tail < s.size()) {
            freq[s[tail] - 'A']++;
            most = max(most, freq[s[tail] - 'A']);
            while (tail - head + 1 - most > k) {
                freq[s[head] - 'A']--;
                head++;
            }
            ans = max(ans, tail - head + 1);
            tail++;
        }
        return ans;
    }
};