/*
寫了三種解法，從 1 到 3 runtime 分別是 272ms->24ms->16ms
第一種最直覺也最慢，用了一個值來檢查有沒有重複，但 erase 實在太花時間了
一直這樣頻繁 erase 的結果就是超慢

第二種用了兩個 pointer，一個跑在前面，只要遇到沒重複的
就把值複製給後面的那個，前面的 pointer 到底後，就把後面的以後都 erase
避免了頻繁 erase 後效率大提升

第三種用到新學的 std::unique
這 function 會把重複的都塞在後面，然後 return 沒重複的有幾個，
所以先用 unique 再把沒重複的數量後的都 erase 掉就完成了
https://en.cppreference.com/w/cpp/algorithm/unique
*/
class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){ return 0; }
        int previous = *nums.begin();
        vector<int>::iterator iter = nums.begin() + 1;
        while(iter != nums.end()){
            if(*iter == previous){
                iter = nums.erase(iter);
            }
            else{
                previous = *iter;
                iter++;
            }
        }
        return nums.size();
    }
};

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){ return 0; }
        int i = 0;
        for(int j = 1; j < nums.size(); j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        nums.erase(nums.begin() + i + 1, nums.end());
        return nums.size();
    }
};

class Solution3 {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};