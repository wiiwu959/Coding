/*
剛做完 3Sum 所以印象深刻，用了相同的方法去做
加上比對和 target 差的動作去找最接近的結果
時間複雜度是 O(n^2)

也有看到用 binary search 的方法，時間複雜較高
不過不管用哪個，一開始的 sort 動作都很必要
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3){
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++){
            int head = i + 1;
            int tail = nums.size() - 1;
            
            while(head < tail){
                int temp = nums[i] + nums[head] + nums[tail];
                if(abs(target - temp) < abs(target - ans)){
                    ans = temp;
                }
                
                if(temp > target ){
                    tail--;
                }
                else if(temp < target){
                    head++;
                }
                else{
                    return target;
                }
            }
        }
        return ans;
    }
};