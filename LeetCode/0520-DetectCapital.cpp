// 題目要符合一個正常詞的大小寫就返回 true
// 全大寫、只有開頭大寫、全小寫 這三種狀況是滿足條件的

// 就只是很簡單的檢查，但聰明一點的寫法 (腦筋急轉彎題?)

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool islow = false;
        bool allup = false;
        if(isupper(word[0])) {
            for(int i = 1; i < word.size(); i++) {
                if(isupper(word[i])) {
                    allup = true;
                    if(islow) { return false; }
                }
                else {
                    islow = true;
                    if(allup) { return false; }
                }
            }
            return true;
        }
        else {
            for(int i = 1; i < word.size(); i++) {
                if(isupper(word[i])) { return false; }
            }
            return true;
        }
    }
};

class Solution {
public:
    bool detectCapitalUse(string word) {
        for(int i=1;i<word.size();i++){
            if( (isupper(word[1]) != isupper(word[i]))  ||  (islower(word[0]) && isupper(word[i])) )
                return false;
        }
        return true;
    }
};