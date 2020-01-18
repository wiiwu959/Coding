// �����W���s��sliding windows����k
// �o�˪��t�׷|��O(n)
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		bool all[256];
		for (int i = 0; i < 256; i++){
			all[i] = false;
		}
		int max = 0, counter = 0, i = 0, j = 0;
		while (i < s.size() && j < s.size()) {
			// ��즳���ơA�N�q�e���}�l����R���A����S�����Ƭ���
			if (all[s[j]] != false) {
				counter--;
				all[s[i]] = false;
				i++;
			}
			// �Y�O�S�����ơA�N�~�򩹤U��
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


// �p�G�M�Ĥ@�Ӱ��k�@�ˡA���O��map����
// �]��find�O�Q�ά��¾�t��k�A�ҥH�L���t�׬Olog n
// �ҥH����C!!
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

// �ɤO�k�A�W~~~�źC�줣�浴�藍�n���V�|�z�F
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