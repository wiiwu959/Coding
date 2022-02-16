// 這題跟上一題很像但要 zigzag traverse，也就是每次從左邊下一次從右邊輪流
// 這裡先用跟上一題不同的方法做出 traverse (用 queue BFS)
// 然後比起一邊的 level order 只加上一個條件判斷而已
// 分別對於不同方向時會用不同的放 ans 方法 (從前面塞或從後面塞)

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) { return ans; }

        queue<TreeNode*> can;
        int count = 0;
        int level = 0;
        
        // true : left2right;
        // false : right2left
        bool from = true;
        
        can.push(root);
        
        while(!can.empty()) {
            count = can.size();
            ans.push_back(vector<int>(count));
            
            for(int i = 0; i < count; i++) {
                TreeNode* running = can.front();
                can.pop();

                if(from) {
                    ans[level][i] = running->val;
                }
                else {
                    ans[level][count - i - 1] = running->val;
                }
                if(running->left) can.push(running->left);
                if(running->right) can.push(running->right);
            }
            from = !from;
            
            level++;
        }
        
        return ans;
    }
};