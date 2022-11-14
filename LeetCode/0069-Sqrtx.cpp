// using binary search
class Solution {
public:
    int mySqrt(int x) {
        int head = 0, tail = x;
        long long mid, power;
        while (tail >= head) {
            mid = head + (tail - head) / 2;
            power = mid * mid;
            if (power > x) {
                tail = mid - 1;
            } else if (power < x) {
                head = mid + 1;
            } else {
                return mid;
            }
        }
        
        return power > x ? mid - 1: mid;
    }
};