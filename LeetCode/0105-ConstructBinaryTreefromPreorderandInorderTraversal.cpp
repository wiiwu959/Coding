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

// 先用一個 map 建立 inorder 的順序 val - index 對應
// recursive 的做 build，每次都會拿範圍內的第一個 node 當作 root
// 然後去找下一次的範圍
class Solution {
public:
    unordered_map<int, int> inorder_val_index;
    TreeNode* build(vector<int>& preorder, int from, int to) {
        if (from > to) { return nullptr; }
        TreeNode* root = new TreeNode(preorder[from]);
        if (from == to) { return root; }
        
        int cursor = inorder_val_index[root->val];
        int stop = from + 1;
        while (stop <= to) {
            if (inorder_val_index[preorder[stop]] < cursor) {
                stop++;
            } else { 
                break; 
            }
        }
        root->left = build(preorder, from + 1, stop - 1);
        root->right = build(preorder, stop, to);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Construct (inorder value - index) map
        for (int i = 0; i < inorder.size(); i++) {
            inorder_val_index[inorder[i]] = i;
        }
        
        return build(preorder, 0, preorder.size() - 1);
    }
};