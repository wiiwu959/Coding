/*
題目是 A 和 B 每次可以移除一個自己的字母
可以移除的條件是左右都是自己的字母，先 A 再 B
看誰先沒步就輸了
*/

// calculate all removable of each side
class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0;
        int b = 0;
        for (int i = 1; i < colors.size() - 1; i++) {
            if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1]) {
                if (colors[i] == 'A') a++;
                else b++;
            }
        }

        if (a > b) return true;
        return false;
    }
};
