// 找出最小的包含目標 string 的 window

// example:
// s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"

// 用的做法就是用 sliding window，先找出從頭開始符合條件的 window
// 找到後開始左邊往前縮，縮到不符合條件的時候右邊開始往後，重複這動作到結束
// 需要注意的是，map int 若是沒有值，+1 會 assign 0 給他，-1 會是 -1 （踩了一下雷）

class Solution {
public:
    string minWindow(string s, string t) {        
        if (s.size() < t.size()) {
            return "";
        }
        
        int flag = 0;
        map<char, int> char_map;
        for (int i = 0; i < t.size(); i++) {
            char_map[t[i]] -= 1;
            flag += 1;
        }
        
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            if (char_map.find(s[right]) == char_map.end()) {
                char_map[s[right]] = 0;
            }
            if (char_map[s[right]] < 0) {
                if (--flag <= 0) {
                    char_map[s[right]]++;
                    break;
                }
            }
            char_map[s[right]]++;
            right++;
        }
        
        if (flag > 0) {
            return "";
        }
        
        int best_left = left;
        int min = right - left + 1;
        while(left < right) {
            char_map[s[left]]--;
            while (char_map[s[left]] < 0 && right <= s.size() - 1) {
                right++;
                char_map[s[right]]++;
            }
            
            if (char_map[s[left]] < 0) {
                break;
            }
            
            left++;
            if ((right - left) < min) {
                best_left = left;
                min = right - left + 1;
            }
        }
        return s.substr(best_left, min);
    }
};