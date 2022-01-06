// 除了會出現重複的值以外通通都跟 033 一樣
// 所以特別處理重複值會讓原本判斷出問題的狀況
// 也就是 left, right, mid 都出現相同的值，就難以判斷哪一邊有照順序排了
// 遇到像是 [1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1], 13 這種測資就會出錯
// 所以遇到三者相同的時候就再給他 head 和 tail 去掉重新檢查看看直到可以判斷

// 複雜度是 O(log n)，最糟 O(n)
// 參考 https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/28218/My-8ms-C%2B%2B-solution-(o(logn)-on-average-o(n)-worst-case)

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
    
        while(left <= right){
            int mid = (right + left)/2;
            
            if(nums[mid] == target){
                return true;
            }
            
            // added
            if((nums[left] == nums[mid]) && (nums[right] == nums[mid])) {
                left++;
                right--;
            }
            else if(nums[mid] <= nums[right]) {
                if(nums[mid] < target && nums[right] >= target){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            else {
                if(nums[mid] > target && nums[left] <= target){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
        } 
        return false;
    }
};