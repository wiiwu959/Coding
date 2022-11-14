// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// 題目要找出從哪個版本開始出錯的
/* 要特別注意 
middle = (left + right) / 2;
這樣會有 int overflow 的風險，所以之後做 binary search 都不建議這樣
*/
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int middle;
        while (left <= right) {
            middle = left + ((right - left) / 2);
            if (isBadVersion(middle)) {
                if (!isBadVersion(middle - 1)) {
                    return middle;
                }
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return -1;
    }
};