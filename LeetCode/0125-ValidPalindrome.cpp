class Solution {
public:
    bool isPalindrome(string s) {
        int head = 0;
        int tail = s.length() - 1;

        while (head < tail) {
            if (!isalnum(s[head])) {
                head++;
                continue;
            }

            if (!isalnum(s[tail])) {
                tail--;
                continue;
            }

            if (tolower(s[head]) != tolower(s[tail])) {
                return false;
            }

            head++; tail--;
        }

        if (tolower(s[head]) == tolower(s[tail])) {
            return true;
        }
        return false;
    }
};