// 題目是會給一個 array，要算有幾組兩個相加會是 60 的倍數

// 若用暴力解會超過時間限制
// 這個方法是用餘數去紀錄，若本身就是 60 的倍數
// 那他就可以和同樣是 60 倍數的值湊一起
// 若他本身不是 60 的倍數，那就得和 mod 後相加會 = 60 的湊一起
// 所以用這方法就能一邊紀錄 mod 後的值一邊算
// 時間複雜度就可以在 O(n)

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        vector<int> mod_time(60, 0);
        for(int i = 0; i < time.size(); i++) {
            int mod = time[i] % 60;
            if(mod == 0) {
                count += mod_time[0];
            }
            else {
                count += mod_time[60 - mod];
            }
            mod_time[mod] += 1;
        }
        return count;
    }
};