/*
檢查一個 Linked List 是不是有回文
*/

// 先用 two pointer 找出中間點，途中用 stack 紀錄 node value
// 找到中間點後就可以開始用後續的值跟 stack 檢查

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
    bool isPalindrome(ListNode* head) {
        stack<int> checking_stack;
        ListNode* tail = head;

        while (tail->next != nullptr && tail->next->next != nullptr) {
            checking_stack.push(head->val);
            tail = tail->next->next;
            head = head->next;
        }

        if (tail->next != nullptr) {
            checking_stack.push(head->val);
        }
        // where the check start
        head = head->next;

        while (head != nullptr && !checking_stack.empty()) {
            if (head->val != checking_stack.top()) {
                return false;
            }
            checking_stack.pop();
            head = head->next;
        }

        if (!checking_stack.empty()) {
            return false;
        }
        return true;
    }
};