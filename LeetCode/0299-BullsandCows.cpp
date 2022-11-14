// 幾 A 幾 B 的遊戲
class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0;
        int b = 0;
        int record[10] = {0};
        for (int i = 0; i < secret.length(); i++) {
            if (guess[i] == secret[i]) {
                a++;
            } else {
                record[secret[i] - '0']++;
            }
        }
        
        for (int i = 0; i < guess.length(); i++) {
            if (guess[i] != secret[i] && record[guess[i] - '0'] > 0) {
                b++;
                record[guess[i] - '0']--;
            }
        }
        
        string ans = to_string(a) + "A" + to_string(b) + "B";
        return ans;
    }
};