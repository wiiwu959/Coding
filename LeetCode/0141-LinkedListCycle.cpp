// 檢查一個 Linked list 有沒有 cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 用一個 hashmap 去記錄走過的 node
// time: O(n), space: O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> visited;
        while (head) {
            if (visited.find(head) != visited.end()) {
                return true;
            } else {
                visited[head] = true;
            }
            head = head->next;
        }
        
        return false;
    }
};

// 用快慢兩個 pointer
// space: O(1), time: O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};