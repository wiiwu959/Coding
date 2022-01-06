/*
這題和 3Sum 系列是一樣的做法，都要靠 sort 和 two pointer 來加快
這題有四個數字所以需要多一點條件判斷，確保不會出現重複的答案
還有特別的一點是在兩個 for loop 開始的時候先加上條件判斷可以大大提升速度
從 68ms -> 8ms

另外這一系列問題有個名字 K-Sum，2Sum 以上是可以用固定的公式去做的
把程式分成 ksum recursive 和 2sum 用 2pointer 就可以解決任何 k 的這種問題了
(2Sum 以上的時間複雜度就沒辦法再大幅優化了)
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4){ return {};}
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0;i < n - 3; i++){
            if(i > 0 && nums[i] == nums[i - 1]){ continue; }
            // 以下兩個 if 是加速用的
            if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target){ break; }
            if(nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target){ continue; }
            for (int j = i + 1; j < n - 2; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]){ continue; }
                // 以下兩個 if 是加速用的
                if(nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target){ break; }
                if(nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target){ continue; }
                int head = j + 1;
                int tail = n - 1;
                while(head < tail){
                    int get = nums[i] + nums[j] + nums[head] + nums[tail];
                    if(get < target){
                        head++;
                    }
                    else if(get > target){
                        tail--;
                    }
                    else{
                        ans.push_back({nums[i], nums[j], nums[head], nums[tail]});
                        do{ head++; }while(nums[head] == nums[head-1] && head < tail);
                        do{ tail--; }while(nums[tail] == nums[tail+1] && head < tail);
                    }
                }
            }
        }
        return ans;
    }
};