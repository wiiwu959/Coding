// 跟 083 類似不過不保留一個有 duplicate 的了
// 也是建議畫圖追追，比 083 多了一個 while 而已，但更需要理解 double linked list

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
        ListNode** now = &head;
        
        while(*now != nullptr) {
            if((*now)->next != nullptr && ((*now)->next->val == (*now)->val)) {
                while((*now)->next != nullptr && ((*now)->next->val == (*now)->val)) {
                    (*now) = (*now)->next;   
                }
                (*now) = (*now)->next;
            }
            else {
                now = &((*now)->next);
            }
        }
        
        return head;
    }

};