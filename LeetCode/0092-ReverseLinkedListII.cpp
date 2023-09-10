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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        int count = 0;

        ListNode* cur = head;
        ListNode* start = nullptr;
        ListNode* finish = nullptr;
        while (cur) {
            count++;
            if (count == left - 1) {
                start = cur;
            }

            if (count == right + 1) {
                finish = cur;
                break;
            }
            cur = cur->next;
        }

        ListNode* from = start ? start->next: head;
        cur = from;
        count = 0;
        ListNode* prev = cur;
        ListNode* next = cur->next;
        while (count < right - left) {
            count++;
            cur = next;
            next = cur->next;
            cur->next = prev;
            prev = cur;
        }

        from->next = finish;
        if (start) start->next = cur;
        else head = cur;
        
        return head;
    }
};