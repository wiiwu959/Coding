// 找兩個 set 的交集
// O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        
        set<int> set2;
        vector<int> ans;
        for(auto n: nums2)
        {
            if(set1.find(n) != set1.end()) 
            { 
                if(set2.find(n) == set2.end()) { ans.push_back(n); }
                set2.insert(n);
            }
        }
        return ans;
    }
};

// stl set 的東東 set_intersection
// https://www.cplusplus.com/reference/algorithm/set_intersection/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1;
        for(auto n : nums1)
        {
            set1.insert(n);
        }
        
        set<int> set2;
        for(auto n : nums2)
        {
            set2.insert(n);
        }
        
        set<int> intersect;
        set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                 std::inserter(intersect, intersect.begin()));
        
        vector<int> ans;
        for(auto n: intersect)
        {
            ans.push_back(n);
        }
        return ans;
    }
};