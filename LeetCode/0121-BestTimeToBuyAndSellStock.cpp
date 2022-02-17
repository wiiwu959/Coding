#include<stdc++.h>
using namespace std;

// 因為目標就是找到最便宜的時候買，最貴的時候賣
// 只要遇到一個更小的值，那用這個最小值去賣的價錢一定比之前遇過的值買進更好
// 所以一路走下去只要遇到有更小值，就把買入值換成這個數

// greedy
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int min = INT_MAX;
        int ans = 0;
        for(auto value : prices)
        {
            if(value < min) 
            {
                min = value;
            }
            
            int profit = value - min;
            if(profit > ans) {ans = profit;}
        }
        return ans;
    }
};