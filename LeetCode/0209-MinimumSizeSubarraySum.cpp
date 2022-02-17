// 要找 array 中超過 target 的最小連續段落

// 用 sliding windows 一邊滑一邊找最接近的
// O(n)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0, num = 0;
        int min = INT_MAX;
        
        while(right < nums.size())
        {
            sum += nums[right];
            num++;
            right++;
            while(sum >= target && left < right)
            {
                if(num < min)
                {
                    min = num;
                }
                sum -= nums[left];
                left++;
                num--;
            }
            
        }
        
        if(min != INT_MAX) { return min; }
        else { return 0; }
        
    }
};