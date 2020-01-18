// �ɤO�k�A���Ӳհ_��sort�᪽����
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

// ��Ӥ�����ɶ���S�g�F�o��
// ���ۤ�M��C�C�e�i��줤���
// �᪺�ɶ���֫ܦh�A�ɶ����������ӬOO((m+n)/2)
// ť�����O(log(min(m+n)))���٨S�Q��
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