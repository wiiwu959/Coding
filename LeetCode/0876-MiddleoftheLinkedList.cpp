// 找到中間的那個 node (如果有兩個，要後面的那一個)

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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        struct ListNode* cur = head;
        struct ListNode* mid = head;
        
        while (cur->next && cur->next->next) {
            cur = cur->next->next;
            mid = mid->next;
        }
        
        if (cur->next) {
            cur = cur->next;
            mid = mid->next;
        }
        
        return mid;
    }
};