/* 
這題對 valid split 的描述是 split 完左右的 dominant number 一樣
dominant number 就是在 array 中出現頻率過半的數字
*/

// 用一個 map 記錄左右兩邊的每個數字的出現頻率
// 一一 split 並檢查那個變動的數字是不是該次 split 的 dominant number
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int m = nums.size();
        unordered_map<int, int> left_split, right_split;

        for (int& num: nums) {
            right_split[num]++;
        }

        for (int i = 0; i < m - 1; i++) {
            left_split[nums[i]]++;
            right_split[nums[i]]--;

            int left_size = i + 1;
            int right_size = m - left_size;
            
            if (left_split[nums[i]] * 2 > left_size &&
                right_split[nums[i]] * 2 > right_size) {
                return i;
            }
        }

        return -1;
    }
};