/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> old_new;
        
        Node* new_head = new Node(head->val);
        old_new[head] = new_head;

        Node* cur = new_head;
        Node* old = head->next;

        while (old) {
            cur->next = new Node(old->val);
            cur = cur->next;
            old_new[old] = cur;
            old = old->next;
        }

        old = head;
        cur = new_head;
        while (old) {
            if (old->random) {
                cur->random = old_new[old->random];
            }
            old = old->next;
            cur = cur->next;
        }
        return new_head;
    }
};