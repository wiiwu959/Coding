/*
如果把用 for 的地方直接用手列在下面會快一點 (faster than 90%)
(現在這樣是 faster than 74%) 但是空間會用多一點點，而且有點醜
*/
class Solution {
public:
    string intToRoman(int num) {
        string roman_list[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X",
                             "IX", "V", "IV", "I"};
        int num_list[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans = "";
        for (int i = 0; i < 13; i++){
            while(num - num_list[i] >= 0){
                num = num - num_list[i];
                ans += roman_list[i];
            }
        }
        return ans;
    }
};