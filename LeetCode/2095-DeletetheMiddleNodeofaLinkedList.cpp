// 題目要求刪去 linked-list 中間的那個值
/*
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Input: head = [1,2,3,4]
Output: [1,2,4]
Input: head = [2,1]
Output: [2]
*/

// 用了三個 pointer 來達到不用 traverse 整個 linked-list
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
    ListNode* deleteMiddle(ListNode* head) {
        
        if (!head->next) {
            return nullptr;
        }
        
        ListNode* first = head;
        ListNode* previous = head;
        ListNode* second = head;
        
        while (second && second->next) {
            previous = first;
            first = first->next;
            second = second->next->next;
        }
        previous->next = first->next;
        delete first;
        return head;
    }
};