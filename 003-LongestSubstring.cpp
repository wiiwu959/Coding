// 網路上說叫做sliding windows的方法
// 這樣的速度會有O(n)
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		bool all[256];
		for (int i = 0; i < 256; i++){
			all[i] = false;
		}
		int max = 0, counter = 0, i = 0, j = 0;
		while (i < s.size() && j < s.size()) {
			// 找到有重複，就從前面開始往後刪掉，直到沒有重複為止
			if (all[s[j]] != false) {
				counter--;
				all[s[i]] = false;
				i++;
			}
			// 若是沒有重複，就繼續往下做
			else {
				counter++;
				all[s[j]] = true;
				j++;
			}
			max = counter > max ? counter : max;
		}
		return max;
	}
};


// 如果和第一個做法一樣，但是用map的話
// 因為find是利用紅黑樹演算法，所以他的速度是log n
// 所以比較慢!!
// https://stackoverflow.com/questions/9961742/time-complexity-of-find-in-stdmap
class Solution2 {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> all;
		int max = 0, counter = 0, i = 0, j = 0;
		while (i < s.size() && j < s.size()) {
			if (all.find(s[j]) != all.end()) {
				counter --;
				all.erase(s[i]);
				i++;
			}
			else {
				counter++;
				all[s[j]] = j;
				j++;
			}
			max = counter > max ? counter : max;
		}
		return max;
	}
};

// 暴力法，超~~~級慢到不行絕對不要用糟糕爆了
class Solution3 {
	int lengthOfLongestSubstring(string s) {
		map<char, int> all;
		map<char, int>::iterator iter;
		int max = 0, counter = 0;
		for (int i = 0; i < s.size(); i++) {
			for (int j = i; j < s.size(); j++) {
				if (all.end() == all.find(s[j])) {
					counter++;
				}
				else { break; }
				if (counter > max) {
					max = counter;
				}
				all[s[j]] = j;
			}
			counter = 0;
			all.clear();
		}
		return max;
	}
};