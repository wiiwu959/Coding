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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){ return head; }
        
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* last = first;
        head = second;
        
        while(1){
            last->next = second;
            first->next = second->next;
            second->next = first;
            last = first;
            if(first->next != nullptr){
                first = first->next;
            } else{ break; }
            
            if(first->next != nullptr){
                second = first->next;
            } else{ break; }
        }
        return head;
    }
};

/*
用 recursive 做，兩種秒數都一樣
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){ return head; }
        
        ListNode* new_head = head->next;
        head->next = swapPairs(new_head->next);
        new_head->next = head;
        
        return new_head;
    }
};