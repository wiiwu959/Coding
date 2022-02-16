// 找出總共多少 level
// 用 backtracking 一層層找

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
    int maxDepth(TreeNode* root) {
        return backtracking(0, root);
    }
    
    int backtracking(int level, TreeNode* now) {
        if(!now) { return level; }
        
        int left = 0, right = 0;
        left = backtracking(level + 1, now->left);
        right = backtracking(level + 1, now->right);
        
        return (right > left) ? right : left;
    }
};