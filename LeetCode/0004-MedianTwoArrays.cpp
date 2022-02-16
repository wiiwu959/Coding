// 暴力法，把兩個組起來 sort 後直接找
class Solution1 {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		nums1.insert(nums1.end(), nums2.begin(), nums2.end());
		sort(nums1.begin(), nums1.end());

		int x = nums1.size() / 2;		// O(nlog2n)
		if (nums1.size() % 2 == 0){
			return (nums1[x] + nums1[x - 1]) / 2.0;
		}
		else{
			return nums1[x];
		}
	}
};

// 後來比較有時間後又寫了這個
// 兩兩相比然後慢慢前進找到中位數
// 花的時間減少很多，時間複雜度應該是 O((m+n)/2)
// 聽說能到 O(log(min(m+n))) 但還沒想到
class Solution {
public:	
	int findNext(vector<int>& nums1, vector<int>& nums2, int* cur1, int* cur2) {
		int next;
		if (*cur2 == nums2.size() - 1) {
			*cur1 = *cur1 + 1;
			return nums1[*cur1];
		}

		if (*cur1 == nums1.size() - 1) {
			*cur2 = *cur2 + 1;
			return nums2[*cur2];
		}

		if (nums1[*cur1 + 1] >= nums2[*cur2 + 1]) {
			*cur2 = *cur2 + 1;
			next = nums2[*cur2];
		}
		else {
			*cur1 = *cur1 + 1;
			next = nums1[*cur1];
		}
		return next;
	}
	
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int totalSize = nums1.size() + nums2.size();
		int cur1 = -1, cur2 = -1, ready = 0, mid = ceil(totalSize / 2.0);
		double ans;
		bool need_div = false;
		if (totalSize % 2 == 0) { need_div = true; }
		while (1) {
			int next = findNext(nums1, nums2, &cur1, &cur2);
			ready++;

			if (ready == mid) {
				if (!need_div) { return next; }
				else {
					int find = findNext(nums1, nums2, &cur1, &cur2);
					ans = (next + find) / 2.0;
					return ans;
				}
			}
		}
	}
};