class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        vector<int> cal_string(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                int mid_result = int(num1[i] - '0') * int(num2[j] - '0') + cal_string[i + j + 1];
                cal_string[i + j + 1] = mid_result % 10;
                cal_string[i + j] += mid_result / 10;
            }
        }

        string ans = "";
        if ((num1[0] != '-' && num2[0] == '-') || (num1[0] == '-' && num2[0] != '-')) {
            ans += '-';
        }

        int pos = 0;
        while (pos < cal_string.size() && cal_string[pos] == 0) pos++;
        for (int i = pos; i < cal_string.size(); i++) {
            ans += (char(cal_string[i] + int('0')));
        }
        return ans;

    }
};