// 題目會給一個 array，要問你能不能分成等量的兩半
// ex. [1,5,11,5] 就可以分成 [1,5,5] 和 [11]



class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) { return false; }
        else { sum = sum / 2;}
        
        sort(nums.begin(), nums.end());
        
        bool ans[10000] = {false};
        ans[0] = true;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = sum + 1; j > 0; j--) {
                if((j - nums[i]) >= 0 && ans[j - nums[i]] == true) {
                    ans[j] = true;
                }   
            }
        }
        // for(int i = 0; i < sum; i++) {
        //     cout << ans[i] << " ";
        // }
        return ans[sum];
    }
};