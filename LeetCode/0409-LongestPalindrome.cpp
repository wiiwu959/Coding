// 找出最長可以組成多長的回文
// Input: s = "abccccdd"
// Output: 7

class Solution {
public:
    int longestPalindrome(string s) {
        int counting[52] = {0};
        int longest = 0;
        for (auto& c: s) {
            int index = int(c) >= 97 ? int(c) - int('a') + 26: int(c) - int('A');
            cout << c;
            counting[index]++;
            if (counting[index] == 2) {
                longest += 2;
                counting[index] = 0;
            }
        }
        
        for (int i = 0; i < 52; i++) {
            if (counting[i] > 0) {
                longest++;
                break;
            }
        }
        
        return longest;
    }
};