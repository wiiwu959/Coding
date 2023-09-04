class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> frq;
        int line = floor(nums.size() / 3);
        set<int> accept;
        for (int& num: nums) {
            frq[num]++;
            if (frq[num] > line) {
                accept.insert(num);
            }
        }

        vector<int> ans;
        ans.assign(accept.begin(), accept.end());

        return ans;
    }
};

// 用 Boyer–Moore majority vote algorithm
// 因為是找 1/3 以上，所以這裡是三消
// 題目沒說一定有答案，所以最後會在檢查一下
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums;
        }

        if (nums.size() == 2) {
            if (nums[0] == nums[1]) {
                return {nums[0]};
            } else {
                return nums;
            }
        }

        int num1 = 0;
        int num2 = 1;
        int count1 = 0;
        int count2 = 0;
               
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num1) {
                count1++;
            } else if (nums[i] == num2) {
                count2++;
            } else {
                if (count1 == 0) {
                    num1 = nums[i];
                    count1++;
                } else if (count2 == 0) {
                    num2 = nums[i];
                    count2++;
                } else {
                    count1--;
                    count2--;
                }
            }
            cout << "num1 = "<<num1<<", num2 = "<<num2<<endl;
        }

        count1 = 0;
        count2 = 0;
        for (int num: nums) {
            if (num == num1) {
                count1++;
            }

            if (num == num2) {
                count2++;
            }
        }

        vector<int> ans;
        int line = floor(nums.size() / 3);
        if (count1 > line) ans.push_back(num1);
        if (count2 > line) ans.push_back(num2);
        return ans;

    }
};