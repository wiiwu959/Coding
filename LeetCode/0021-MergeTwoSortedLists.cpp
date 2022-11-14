/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// 這題主要是熟悉 linked list 的題目
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		struct ListNode *start, *now;
        
        if(!l1) {
            return l2;
        }
        
        if(!l2) {
            return l1;
        }
        
		if (l1->val <= l2->val) {
			start = l1;
			l1 = l1->next;
		}
		else {
			start = l2;
			l2 = l2->next;
		}
		now = start;
		
		while (l1 && l2) {
			if (l1->val <= l2->val) {
				now->next = l1;
				l1 = l1->next;
			}
			else {
				now->next = l2;
				l2 = l2->next;
			}
			now = now->next;
		}

		if (l1) {
			now->next = l1;
		}
		else if (l2) {
			now->next = l2;
		}
		return start;
    }
};

// recursive 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) {
            return list2;
        }
        
        if(!list2) {
            return list1;
        }
        
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};