// 把 linked list 反過來

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
// iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        
        struct ListNode* cur = head->next;
        head->next = nullptr;
        
        struct ListNode* cur_next;
        
        while (cur) {
            cur_next = cur->next;
            cur->next = head;
            head = cur;
            cur = cur_next;
        }
        return head;
    }
};

// recursive
// 把 ptr 的箭頭一一往回指，然後最終 return 的是最後一個 node (新的 head)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // if head->next is null, means that "head" is the last node of the list
        // return the last node
        if (!head || !head->next) {
            return head;
        }
        
        // Get the last node of the list
        // (which will be the new head after reversed)
        struct ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
};