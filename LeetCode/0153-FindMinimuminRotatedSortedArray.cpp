// 題目是個 rotate 過的 sort  要找最小的那個 [4,5,6,7,0,1,2] return 0

// Binary search，跟 033 很類似

class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid, low = 0, high = nums.size() - 1;
        
        while(low < high)
        {
            mid = (high + low) / 2;
            // 整個範圍都有照順序
            if(nums[low] < nums[high]) 
            {
                return nums[low];
            }
            // 右半邊有照順序，最小可能在 low - mid 之間
            else if(nums[mid] < nums[high])
            {
                high = mid;
            }
            // 右半邊沒有照順序，最小可能就在右半邊
            else
            {
                low = mid + 1;
            }
        }
        return nums[low];
    }
};