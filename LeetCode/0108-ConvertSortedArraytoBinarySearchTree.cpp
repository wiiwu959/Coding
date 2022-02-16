// 把 sorted array 建成高度平衡的 tree
// 用 backtracking 去依序處理每個 node 和他的節點

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return backtracking(nums, 0, nums.size() - 1);
    }
    
    TreeNode* backtracking(vector<int>& nums, int head, int tail) {
        if(head > tail) {
            return nullptr;
        }
        
        int mid = (tail + head) / 2;
        
        TreeNode* ans = new TreeNode(nums[mid]);
        ans->left = backtracking(nums, head, mid - 1);
        ans->right = backtracking(nums, mid + 1, tail);
        
        return ans;
    }
};