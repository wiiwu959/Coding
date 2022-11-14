// 給 string array 要找出長度最長的 unique substring （不能重複字母）

// 用 Backtracing 把可以接在一起的字串傳下去，然後單純的用 array 紀錄來檢查兩個 string 是否 unique
class Solution {
public:
    int maxLength(vector<string>& arr) {
        return getMax(arr, "", 0);
    }
    
    int getMax(vector<string>& arr, string str, int index) {
        int max = str.length();
        for (int i = index; i < arr.size(); i++) {
            if (isUnique(str, arr[i])) {
                int x = getMax(arr, str + arr[i], i + 1);
                max = x > max ? x : max;
            }
        }
        return max;
    }
    
    bool isUnique(string str1, string str2) {
        vector<bool> mapping(26, false);
        for (int i = 0; i < str1.length(); i++) {
            if (mapping[str1[i] - 'a']) {
                return false;
            }
            mapping[str1[i] - 'a'] = true;
        }

        for (int i = 0; i < str2.length(); i++) {
            if (mapping[str2[i] - 'a']) {
                return false;
            }
            mapping[str2[i] - 'a'] = true;
        }
        return true;
    }
};

// 另外還有用 bit mask 來檢查 unique 的方式
// 以及用 dp 來記錄最大值的方式