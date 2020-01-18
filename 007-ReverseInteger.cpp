// 這題主要就是處理極限值要特別注意
// 他有限制範圍在[−2^31,  2^31 − 1]之間，超過必須回傳0
// 如果去看網站的solution的話，會發現他還刻意多判斷了
// 假設ans == INT_MIN / 10時的狀況(也就是很極限的狀況)
// 但是我實際去測測看發現根本不用擔心會遇到
// 因為他的input一定是int不可能大於或小於INT的極限值
class Solution {
public:
	int reverse(int x) {
		int ans = x % 10;
		x /= 10;
		while (x != 0) {
			if (ans > INT_MAX / 10 || ans < INT_MIN / 10) { return 0; }
			ans *= 10;
			ans += x % 10;
			x /= 10;
		}
		return ans;
	}
};