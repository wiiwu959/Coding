// bubble sort -> O(n^2)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j < nums.size(); j++) {
                if (nums[j] < nums[j - 1]) {
                    int tmp = nums[j];
                    nums[j] = nums[j - 1];
                    nums[j - 1] = tmp;
                }
            }
        }
    }
};


// Similar to quick sort (Dutch national flag)
class Solution { 
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = i, k = nums.size() - 1;
        
        while(j <= k){
            if(nums[j] == 0) swap(nums[i++], nums[j++]);
            else if(nums[j] == 1) j++;
            else swap(nums[k--], nums[j]);
        }
    }
}; 
