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