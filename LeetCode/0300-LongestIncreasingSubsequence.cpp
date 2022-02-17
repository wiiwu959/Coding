#include<stdc++.h>
using namespace std;


// [10,9,2,5,3,7,101,18]
// [0,1,0,3,2,3]
// [7,7,7,7,7,7,7]
// [4,10,4,3,8,9]

class Solution {
public:
    void print_record(vector<int> record)
    {
        for(auto r : record)
        {
            cout << r << " ";
        }
        cout << endl;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> record(nums.size(), 1);
        int max = 1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(record[i] <= record[j] && nums[i] > nums[j]) {
                    record[i] = record[j] + 1;
                }
            }
            if(record[i] > max) { max = record[i]; }
            // print_record(record);
        }
        return max;
    }
};