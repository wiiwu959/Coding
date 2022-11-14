/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 用 iterative 的方式去訪問 inorder 順序的 node
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> can;
        TreeNode* current = root;
        long max = (long)INT_MIN - 1;
        while(!can.empty() || current!= nullptr) {
            if (current != nullptr) {
                can.push(current);
                current = current->left;
            }
            else{
                TreeNode* now = can.top();
                can.pop();
                if(max >= now->val) { return false; }
                max = now->val;
                current = now->right;
            }
        }
        return true;
    }
};

// 用 recursive 先造出 inorder 順序
// 直接用這個順序去檢查
class Solution {
public:
    void inorder(TreeNode* root, stack<int>& st) {
        if (!root) { return; }
        inorder(root->right, st);
        st.push(root->val);
        inorder(root->left, st);
    }
    
    bool isValidBST(TreeNode* root) {
        stack<int> st;
        inorder(root, st);
        
        int cur = st.top();
        st.pop();
        while (!st.empty()) {
            if (st.top() <= cur) {
                return false;
            }
            cur = st.top();
            st.pop();
        }
        return true;
    }
};