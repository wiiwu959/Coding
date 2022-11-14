// 給一個 array 裡面會有數字 1 ~ n，但是有一個數字會被代換掉
// 所以就是會缺一個數字和重複一個數字，要找出來

// Input: nums = [1,2,2,4]
// Output: [2,3]

// 我用個 array 紀錄，O(n)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup = -1;
        vector<bool> mapping(nums.size() + 1, false);
        for (int& i: nums) {
            if (mapping[i] == true) {
                dup = i;
            } else {
                mapping[i] = true;
            }
        }
        
        for (int i = 1; i < mapping.size(); i++) {
            if (!mapping[i]) {
                return {dup, i};
            }
        }
        return {0, 0};
    }
};