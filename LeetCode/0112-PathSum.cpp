// 找出有沒有到 leaf 的路徑合 == target
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) { return false; }
        return backtracking(0, root, targetSum);
    }
    
    bool backtracking(int current, TreeNode* running, int targetSum) {
        if(!running->left && !running->right) {
            if(current + running->val == targetSum)
                return true;
            else
                return false;
        }
        
        bool ans = false;
        if(running->left) {
            ans = ans || backtracking(current + running->val, running->left, targetSum);
        }
        if(running->right) {
            ans = ans || backtracking(current + running->val, running->right, targetSum);
        }
        return ans;
    }
};