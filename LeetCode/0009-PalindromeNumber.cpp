class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x % 10 == 0 && x != 0)) { return false; }
		int rev = 0;
		while (x >= rev) {
			rev += x % 10;
			if (x == rev) { return true; }
			x /= 10;
			if (x == rev) { return true; }
			rev *= 10;
		}
		return false;
	}
};