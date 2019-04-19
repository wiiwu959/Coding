#include <iostream>
#include <map>
#include <string>

using namespace std;

// �����W���s��sliding windows����k
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> all;
		int max = 0, counter = 0, i = 0, j = 0;
		while (i < s.size() && j < s.size())
		{
			
			if (all.find(s[j]) != all.end())	// ��즳���ơA�N�q�e���}�l����R���A����S�����Ƭ���
			{
				counter --;
				all.erase(s[i]);
				i++;
			}
			else								// �Y�O�S�����ơA�N�~�򩹤U��
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

// �ɤO�k�A�W~~~�źC�줣�浴�藍�n���V�|�z�F
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