// 照 preorder 的順序印出一個 tree

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

// DFS
// 用 recursive 的方式
class Solution {
public:
    void add_child(vector<int>& ans, vector<Node*> children) {
        for (Node* n: children) {
            ans.push_back(n->val);
            add_child(ans, n->children);
        }
    }
    
    vector<int> preorder(Node* root) {
        if (!root) {return {};}
        vector<int> ans;
        ans.push_back(root->val);
        add_child(ans, root->children);
        
        return ans;
    }
};

// iterative
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) {return {};}
        stack<Node*> to_visit;
        vector<int> ans;
        to_visit.push(root);
        
        while (!to_visit.empty()) {
            Node* cur = to_visit.top();
            to_visit.pop();
            ans.push_back(cur->val);
            
            for (int i = cur->children.size() - 1; i >= 0; i--) {
                to_visit.push(cur->children[i]);
            }
        }
        return ans;
        
    }
};