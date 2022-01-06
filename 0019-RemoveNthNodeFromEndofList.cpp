/*
直接照他的提示做 one pass 的
hint : Maintain two pointers and update one with a delay of n steps.
用兩個 pointer 來記錄，就不用到底以後重新跑一次了
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tail = head;
        ListNode* run = head;
        for(int i = 0;i < n; i++){
            tail = tail->next;
        }
        
        // 這個 if 是遇到要刪的正好是開頭的時候用的
        // 這種狀況 tail 會直接指到底，跑下面的 while 會出錯
        if(tail == nullptr){
            return head->next;
        }
        while(tail->next != nullptr){
            run = run->next;
            tail = tail->next;
        }
        run->next = run->next->next;
        return head;
    }
};