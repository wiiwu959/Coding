// 直接掃一遍 O(n)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

// 用到 binary search
// 但若是用把問題分成小部份解決的想法就很簡單
// 每次只需要知道 target 在哪一半邊就好
// 至於那一半有沒有因為 rotate 而亂掉就不管，交給下一次處理
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
    
        while(left <= right){
            int mid = (right + left)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            
            // 不管有沒有 rotation，右半邊是照順序的狀態
            if(nums[mid] < nums[right]) {
                // target 在右半邊
                if(nums[mid] < target && nums[right] >= target){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            // 右半邊有 rotation 所以不是全部照順序的狀態
            else {
                // target 在左半邊
                if(nums[mid] > target && nums[left] <= target){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
        } 
        return -1;
    }
};