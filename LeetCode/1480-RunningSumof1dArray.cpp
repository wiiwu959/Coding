// 題目給一個 1D array 要輸出前面的總和
// Input : [1,2,3,4]
// Output : [1,3,6,10]

// 這樣一路加下去會是 O(1) 的答案
// 但是如果直接用 nums (input array) 去加下去可以讓 space 省一點
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans.push_back(sum);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i - 1] + nums[i];
        }
        return nums;
    }
};