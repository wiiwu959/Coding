/*
檢查一個數字是不是 Happy Number
如果這個數字一直拆開、平方、相加後，最後得到 1 就是 Happy
若不是 1 或是陷入迴圈就不是

ex.
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

class Solution {
public:
    map<int, bool> have_been;
    bool isHappy(int n) {
       int check = 0;

       if (have_been.find(n) != have_been.end()) {
            if (have_been[n] == true) {
                return true;
            } else {
                return false;
            }
       }
       
       while (n > 9) {
           int t = n % 10;
           n = n / 10;
           check += t * t;
       }
       check += n * n;
       
       if (check == 1) {
           have_been[n] = true;
           return true;
       }
       
       have_been[n] = false;
       return isHappy(check);
    }
};