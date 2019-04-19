#include <iostream>
#include <map>
#include <string>

using namespace std;

// 網路上說叫做sliding windows的方法
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> all;
		int max = 0, counter = 0, i = 0, j = 0;
		while (i < s.size() && j < s.size())
		{
			
			if (all.find(s[j]) != all.end())	// 找到有重複，就從前面開始往後刪掉，直到沒有重複為止
			{
				counter --;
				all.erase(s[i]);
				i++;
			}
			else								// 若是沒有重複，就繼續往下做
			{
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
class Solution2 {
	int lengthOfLongestSubstring(string s) {
		map<char, int> all;
		map<char, int>::iterator iter;
		int max = 0, counter = 0;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i; j < s.size(); j++)
			{
				if (all.end() == all.find(s[j]))
				{
					counter++;
				}
				else { break; }

				if (counter > max)
				{
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