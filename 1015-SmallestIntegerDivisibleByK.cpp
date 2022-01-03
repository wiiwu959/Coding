// 題目要找幾個 1 組成的數字能被 k 整除

// 需要注意的是停止的條件，找到什麼程度該停下來
// 當除到一個程度以後，餘數就會開始無限循環，所以餘數如果開始重複了就該停了
// 可以用直式除法的思維去想，所以這個寫法就像是每次算完以後再從最尾巴補 1 的概念

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int i = 1;
        long long int num = 1;
        set<int> used;
        
        while(num % k != 0) {
            num = (num * 10 + 1) % k;
            if(used.find(num % k) == used.end()) {
                used.insert(num);
            }
            else {
                return -1;
            }
            i++;
        }
        return i;
    }
};