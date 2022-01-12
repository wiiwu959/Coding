// 一層一層輸出 binary tree
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]

// 用 backtracking

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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        TreeNode* running = root;
        queue<TreeNode*> can;
        vector<vector<int>> ans;
        backtracking(0, root, ans);
        return ans;
    }
    
    void backtracking(int level, TreeNode* node, vector<vector<int>>& ans) {
        if(node == nullptr) return;
        
        if(ans.size() < level + 1) {
            ans.push_back({node->val});
        }
        else {
            ans[level].push_back(node->val);
        }
        
        if(node->left)
            backtracking(level + 1, node->left, ans);
        if(node->right)
            backtracking(level + 1, node->right, ans);
        
        return;

    }
};