// 題目給一個 array 然後你要 rotate 它 k 個位置
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// 有提到至少有三種解法

// 我的第一種就是用 vector 的 function 做，找到 rotate 完新的頭然後移動
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int newOne = nums.size() - k;
        
        vector<int> ans(nums.begin() + newOne, nums.end());
        ans.insert(ans.end(), nums.begin(), nums.begin() + newOne);
        
        nums = ans;
    }
};

// 題目想要 space O(1) 的答案
// 網路上看到的神奇算法
class Solution 
{
public:
    void rotate(int nums[], int n, int k) 
    {
        k = k % n;

        // Reverse the first n - k numbers.
        // Index i (0 <= i < n - k) becomes n - k - i.
        reverse(nums, nums + n - k);
        
        // Reverse tha last k numbers.
        // Index n - k + i (0 <= i < k) becomes n - i.
        reverse(nums + n - k, nums + n);
        
        // Reverse all the numbers.
        // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
        // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
        reverse(nums, nums + n);
    }
};