struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ansHead = new ListNode(0);
		ListNode* ans = ansHead;
		int carry = 0;
		while (l1 != NULL || l2 != NULL) {
			int a = 0, b = 0;
			if (l1 != NULL) { a = l1->val; }
			if (l2 != NULL) { b = l2->val; }
			ans->next = new ListNode((a + b + carry) % 10);
			carry = (a + b + carry) / 10;
			if (l1 != NULL) { l1 = l1->next; }
			if (l2 != NULL) { l2 = l2->next; }
			ans = ans->next;
		}

		if (carry != 0){
			ans->next = new ListNode(carry);
		}
		return ansHead->next;
	}
};