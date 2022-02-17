// 把重複的項目從 sorted linked list 中拿出來

// 就是練習 linkedlist ... 好難
// 用 double pointer 會讓 code 明晰一點，不過會需要想一下
// 建議練習的時候要再畫圖思考一下

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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode** now = &head;
        
        while(*now != nullptr) {
            if((*now)->next != nullptr && ((*now)->next->val == (*now)->val)) {
                (*now) = (*now)->next;
            }
            else {
                now = &((*now)->next);
            }
        }
        
        return head;
    }

};