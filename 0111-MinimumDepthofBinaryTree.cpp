// 找最小淺的深度
// 用 while + queue 的方法每層去 traverse，只要遇到當層是底的就可以 return 了

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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> record;
        int level = 0;
        if(root) { record.push(root); }
        
        while(!record.empty()) {
            level += 1;
            int count = record.size();
            for(int i = 0; i < count; i++) {
                TreeNode* running = record.front();
                record.pop();
                
                if(!running->left && !running->right)
                    return level;
                
                if(running->left)
                    record.push(running->left);
                if(running->right)
                    record.push(running->right);
            }
        }
        return level;
    }
};