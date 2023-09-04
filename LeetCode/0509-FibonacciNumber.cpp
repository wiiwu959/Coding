class Solution {
public:
    unordered_map<int, int> fibo;
    Solution() {
        fibo[0] = 0;
        fibo[1] = 1;
    }

    int fib(int n) {
        if (fibo.find(n) != fibo.end()) {
            return fibo[n];
        }

        fibo[n] = fib(n - 1) + fib(n - 2);
        return fibo[n];
    }
};