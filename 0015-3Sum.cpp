/* 
這題要用 vector<int> 中的數字湊出各種加總 = 0 的三個數字
最重要的一點就是要先 sort 這個 vector 這個 vector 中的值才能加速
不然就要用完全暴力法 時間複雜會是 O(N^3)

這題我用的方法是用 for 把每個數字都跑一遍，每次都只考慮和它之後的數字湊，避掉重複
然後因為有 sort 過，所以可從最靠前和最靠後來湊
接著避免重覆，front 也會一直往前移動
這樣的寫法效率應該會是 O(N^2)
*/ 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++){
            // 因為三個數字相加要 = 0，所以代表任意兩個數字相加要能和第三個數相加 = 0
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;
            while(front < back){
                if((nums[front] + nums[back]) > target){
                    back--;
                }
                else if((nums[front] + nums[back]) < target){
                    front ++;
                }
                else{
                    vector<int> triplets(3, 0);
                    triplets[0] = nums[i];
                    triplets[1] = nums[front];
                    triplets[2] = nums[back];
                    ans.push_back(triplets);
                    while (front < back && nums[front] == triplets[1]){
                        front++;
                    }
                }
            }
            while(i + 1 < nums.size()  && nums[i] == nums[i + 1]){
                i++;
            }
        }            
        return ans;
    }
};