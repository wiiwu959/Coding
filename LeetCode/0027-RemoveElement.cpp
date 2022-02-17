/*
4ms， 用 two pointer做
因為題目強調 array 回傳數量後的東西不會去檢查，
所以就用類似 swap 的方法來做
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1;
        while(i <= j){
            if(nums[j] == val){ j--; }
            else if(nums[i] == val){
                nums[i] = nums[j];
                i++; j--;
            }
            else{ i++; }
        }
        return j + 1;
    }
};