// 題目要求 O(log N)
// 找出區域內的 peek，也就是比左右兩個值都大，return index

// 為了符合要求，這個複雜度可以用 binary search 達成
// 從 mid 開始找，只要比左右都大的就是極端值，否則就往大的那一邊找

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = (left + right) / 2;
            
            if(left == right) {
                return mid;
            }
            
            if(left == mid) {
                if(nums[left] > nums[right]) {
                    return left;
                }
                else {
                    return right;
                }
            }
            
            if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]){
                return mid;
            }
            else if(nums[mid - 1] > nums[mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};