/*
這題影響時間最大的因素就是對應 roman 和 int 的方法了
試過之後像這樣用 function return switch 的值是最快的
其他的速度:
	把 switch 塞在同function > map > unordered_map
*/
class Solution {
public:
	int getVal(char cur) {
		switch (cur) {
			case 'I': return 1;
			case 'V': return 5;
			case 'X': return 10;
			case 'L': return 50;
			case 'C': return 100;
			case 'D': return 500;
			case 'M': return 1000;
			default: return 0;
		}
	}

	int romanToInt(string s) {
		int ans = 0, now = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			int num = getVal(s[i]);
			if (num >= now) {
				ans += num;
				now = num;
			}
			else {
				ans -= num;
			}
		}
		return ans;
	}
};