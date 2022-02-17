/*
這一題如果不知道演算法其實很難想，我一直失敗後就去查相關演算法
先從最後面往前找沒有漸漸增加的瞬間，再往回找比他稍大的值互換，之後從那一個位子之後重新排列
https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
https://leetcode.com/problems/next-permutation/discuss/13867/C%2B%2B-from-Wikipedia
用的時間 0ms，記憶體 93.3%，如果 sort 改成 reverse 會花比較多記憶體，速度一樣
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1){
            return;
        }
        
        for (int i = nums.size() - 1;i > 0; i--){
            if(nums[i - 1] < nums[i]){
                int current = i;
                int close = i;
                while(current < nums.size()){
                    if(nums[current] <= nums[close] && nums[current] > nums[i - 1]){
                        close = current;
                    }
                    current ++;
                }
                swap(nums[i - 1], nums[close]);
                sort(nums.begin() + i, nums.end());
                return;
            }
        }
        
        reverse(nums.begin(), nums.end());
    }
};