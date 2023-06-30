/*
把一個 list 變成 odd list + even list;
1,2,3,4,5,6 -> 1,3,5,2,4,6
*/

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* current = even->next;

        ListNode* even_head = even;

        bool is_odd = true;
        while (current != nullptr) {
            if (is_odd) {
                odd->next = current;
                odd = current;
                current = current->next;
            } else {
                even->next = current;
                even = current;
                current = current->next;
            }
            is_odd = !is_odd;
        }

        odd->next = even_head;
        even->next = nullptr;
        return head;
    }
};