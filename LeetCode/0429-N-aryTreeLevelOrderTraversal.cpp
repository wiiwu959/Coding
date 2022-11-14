// 回傳 level 順序的 tree，每一層要在同一個 vector 裡面
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

// 除了單純的照 level 順序印出，還需要分層
// 所以需要用個值來紀錄每一層有幾的 node
// 因為每次只會處理一層和知道下一層的 node 數，所以只需要兩個數字紀錄
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) {return {};}
        vector<vector<int>> ans;
        queue<Node*> to_visit;
        
        int next = 0;
        
        to_visit.push({root});
        int count = 1;
        
        vector<int> temp;
        while (!to_visit.empty()) {
            Node* cur = to_visit.front();
            temp.push_back(cur->val);
            to_visit.pop();
            count--;
            
            for (Node* n: cur->children) {
                to_visit.push(n);
                next++;
            }
            
            if (count == 0) {
                count = next;
                next = 0;
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};