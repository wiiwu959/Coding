// 一層一層輸出 binary tree
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]


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

// 用 backtracking
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

// iterative
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {return {};}
        
        int next_num = 0;
        queue<TreeNode*> to_visit;
        vector<vector<int>> ans;
        
        to_visit.push(root);
        int num = 1;
        while (!to_visit.empty()) {
            vector<int> temp;
            for (int i = 0; i < num; i++) {
                TreeNode* cur = to_visit.front();
                to_visit.pop();
                temp.push_back(cur->val);
                
                if (cur->left) {
                    to_visit.push(cur->left);
                    next_num++;
                }
                
                if (cur->right) {
                    to_visit.push(cur->right);
                    next_num++;
                }
            }
            ans.push_back(temp);
            num = next_num;
            next_num = 0;
        }
        return ans;
    }
};