// Pow(x,n)

class Solution {
public:
    double myPow(double x, int n) {
        double sum = 1;
        while (n) {
            // 最後到 n = 1 的時候一定會進到這，再來處理正負數即可
            if(n % 2) 
            {
                if(n > 0) { sum *= x; }
                else { sum /= x; }
            }
            x = x * x;
            n /= 2;
        }
        return sum;
    }
};