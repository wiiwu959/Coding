#include <iostream>
#include <vector>
#include <map>

using namespace std;


// 我用的解法，用暴力法解的-->O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(target == nums[i] + nums[j])
                {
                    ans[0] = i;
                    ans[1] = j; 
                    return ans;
                }
            }
        }
        return ans;
    }
    
};


// 利用map來解，只有O(n)而已
class Solution2 {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> ans;
            map<int, int> indexMap;                     // 第一個放value，第二個放index
            map<int, int>::iterator iter;

            for(int i=0; i<nums.size(); i++)
            {
                iter = indexMap.find(target-nums[i]);
                if(iter != indexMap.end())              // 如果有找到，他就是我們要的答案了!
                {
                    ans.push_back(iter->second);        // iter->second就是(target-nums[i])的index
                    ans.push_back(i);
                    return ans;
                }
                indexMap[nums[i]]=i;                    // 若是找不到target-num[i]的值就把它放進map裡
            }

            return ans;
        }
    };