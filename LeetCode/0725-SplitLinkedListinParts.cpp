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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* cur = head;
        while (cur) {
            len++;
            cur = cur->next;
        }

        int more = len % k;
        len = len / k;
        vector<ListNode*> ans;
        cur = head;

        int count = 0;
        ans.push_back(head);
        while (cur) {
            count++;
            if (!more && count >= len) {
                ListNode* to_null = cur;
                cur = cur->next;
                to_null->next = nullptr;
                if (cur) ans.push_back(cur);
                count = 0;
            } else if (count > len) {
                if (count > len) more--;
                ListNode* to_null = cur;
                cur = cur->next;
                to_null->next = nullptr;
                if (cur) ans.push_back(cur);
                count = 0;
            }else {
                cur = cur->next;
            }
        }

        // append left null
        len = k - ans.size();
        for (int i = 0; i < len; i++) {
            ans.push_back(nullptr);
        }

        return ans;
    }
};