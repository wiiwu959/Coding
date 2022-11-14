// 看這個 linked list 是不是 cycle 並回傳 cycle 開始的那個 node

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 用一個叫做 Floyd Cycle Algorithm 的方法
// 先用 fast-slow pointer 找到交會的那個 node
// 找到後，從起點和那個 node 分別一起往前一步一步，直到兩個 node 會合
// space: O(1),time: O(n)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            
            if (fast == slow) {
                ListNode* slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};