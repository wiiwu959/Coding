/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// recursive
class Solution {
public:
    void push_child(vector<int>& ans, vector<Node*> children) {
        for (Node* n: children) {
            push_child(ans, n->children);
            ans.push_back(n->val);
        }
    }
    vector<int> postorder(Node* root) {
        if (!root) {return {};}
        vector<int> ans;
        push_child(ans, root->children);
        ans.push_back(root->val);
        return ans;
    }
};

// iterative
class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root) {return {};}
        
        stack<pair<Node*, bool>> to_visit;
        vector<int> ans;
        
        to_visit.push({root, false});
        
        while (!to_visit.empty()) {
            pair<Node*, bool> cur = to_visit.top();
            if (!cur.second && cur.first->children.size() != 0) {
                to_visit.top().second = true;
                for (int i = cur.first->children.size() - 1; i >= 0; i--) {
                    to_visit.push({cur.first->children[i], false});
                }
            } else {
                ans.push_back(cur.first->val);
                to_visit.pop();
            }
            
        }
        return ans;
    }
};

