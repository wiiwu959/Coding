// 題目是要找二補數

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) { return 1; }
        
        int exp = pow(2, floor(log2(n)) + 1) - 1;
        return exp ^ n;
    }
};