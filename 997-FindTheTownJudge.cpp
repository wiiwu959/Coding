// 題目要找出 town judge，他不信任別人但被大家信任
// 會給一個 trust list，裡面會是一組一組的 a trust b

// 所以就用 unordered_map 紀錄誰沒有信任任何人
// 然後用一個 vector 紀錄每個人被信任的次數

// time complexity of find : set -> O(log n), unordered_map -> O(1)

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, bool> trust_other;
        // set<int> trust_other;
        vector<int> be_trust(n + 1, 0);
        
        for(int i = 0; i < trust.size(); i++) {
            trust_other[trust[i][0]] = true;
            // trust_other.insert(trust[i][0]);
            be_trust[trust[i][1]]++;
        }
        
        for(int i = 1; i <= n; i++) {
            if(trust_other.find(i) == trust_other.end()) {
                if(be_trust[i] == n - 1) {
                    return i;
                }
            }
        }
        return -1;
    }
};

// 小明教我的一個他看到的時間複雜度一樣但更省空間的作法
// 只用一個 array 來記錄，好聰明，我大概沒辦法自己想到
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> be_trust(n + 1, 0);
        
        for(int i = 0; i < trust.size(); i++) {
            be_trust[trust[i][0]]--;
            be_trust[trust[i][1]]++;
        }
        
        for(int i = 1; i <= n; i++) {
            if(be_trust[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};