// 題目要把相同組成的整理起來
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// 用 sort + hash map 做
// 另外不用 sort 的方法會更快，概念就是用別的方法找出辨識方法
// 像是用每個字母數作為 id 之類的
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> table;
        for(auto& str: strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            
            if(table.find(temp) != table.end())
            {
                ans[table[temp]].push_back(str);
            }
            else
            {
                table[temp] = ans.size();
                ans.push_back({str});
            }
        }
        return ans;
    }
};