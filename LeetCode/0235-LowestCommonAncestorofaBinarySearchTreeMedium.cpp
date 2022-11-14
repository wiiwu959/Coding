/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 找到兩個 node 屬於誰的 subtree
// node 自己也可以算是自己的 parent
// 因為是個 Binary Search Tree 所以很好解決
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        
        while (cur->left && cur->right) {
            if (p->val < cur->val && q->val < cur->val) {
                cur = cur->left;
            } else if (p->val > cur->val && q->val > cur->val) {
                cur = cur->right;
            } else {
                return cur;
            }
        }
        return cur;
    }
};