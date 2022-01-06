// 把重複的項目從 sorted linked list 中拿出來

// 就是練習 linkedlist ... 好難

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) { return head; }
        ListNode* now = head;
        int current = now->val;
        while(now->next != nullptr) {
            if(now->next->val == current) {
                now->next = (now->next->next == nullptr)? nullptr: now->next->next;
            }
            else {
                current = now->next->val;
                now = now->next;
            }
        }

        return head;
    }
};