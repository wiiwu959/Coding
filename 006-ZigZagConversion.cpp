// 用vector<string>來存每一行的內容
// 最後併在一起印出來得到答案
// 時間複雜O(n)

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) { return s; }

		int currentRow = 0, i = 0;
		vector<string> rowArray(numRows, "");
		while (i < s.length()) {
			while (currentRow < numRows && i < s.length()) {
				rowArray[currentRow] += s[i];
				currentRow++;
				i++;
			}
			if (currentRow == numRows) {
				currentRow-=2;
			}
			while (currentRow > 0 && i < s.length()) {
				rowArray[currentRow] += s[i];
				currentRow--;
				i++;
			}
		}
		string ans = "";
		for (i = 0; i < numRows; i++) {
			ans += rowArray[i];
		}
		return ans;
	}
};