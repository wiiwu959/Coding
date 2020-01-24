// 其實這題很爛，只是if-else練習還有一堆奇怪的testcase
// 有看到效率比較好的寫法但是也覺得沒什麼意義就沒繼續改了
// 不過還是有收穫，就是下面sulution2的寫法，超神奇
// 他只會讀進數字的部分，而且奇怪的case也都會過，神奇!
class Solution {
public:
	int myAtoi(string str) {
		bool positive = true, start = false;
		int test = INT_MAX / 10;
		long int ans = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '-' && (!start)) {
				positive = false;
				start = true;
				continue;
			}

			if (str[i] == '+' && (!start)) {
				start = true;
				continue;
			}
			
			if (str[i] <= '9' && str[i] >= '0') {
				start = true;
				int digit = int(str[i] - 48);
				if (ans > test) {
					if (positive) { return INT_MAX; };
					if (!positive) { return INT_MIN; };
				}
				if (ans == test) {
					if (positive && digit >= 7) { return INT_MAX; };
					if (!positive && digit >= 8) { return INT_MIN; };
				}
				ans *= 10;
				ans += digit;
			}

			if (!isdigit(str[i]) && str[i] != ' ') {
				break;
			}
			if (str[i] == ' ' && start) {
				break;
			}
		}

		if (!positive) {
			ans *= -1;
		}

		return ans;
	}
};

class Solution2 {
public:
	int myAtoi(string str) {
		stringstream s(str);
		int a = 0;
		s >> a;
		return a;
	}
};