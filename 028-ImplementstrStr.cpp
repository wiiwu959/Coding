/*
用了 Brute force 效率還算可以 O(m*n)
另外有種叫做 KMP 的演算法可以用會再快一點
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()){ return 0;}
        int j = 0;
        for(int i = 0; i < haystack.size(); i++){
            if(haystack[i] == needle[j]){
                j++;
            }
            else{
                i -= j; j = 0;
            }
            if(j == needle.size()){ return i - j + 1; }
        }
        return -1;
    }
};

/*
結果花時間去理解了，寫出來沒有比較快
空間反而還花多了一點
照理說應該有變快啦，時間複雜應該變 O(m+n)
講解 KMP :
https://medium.com/nlp-tsupei/kmp%E7%AE%97%E6%B3%95%E8%A9%B3%E8%A7%A3-1b1050a45850
https://www.youtube.com/watch?v=BXCEFAzhxGY
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()){ return 0;}
        vector<int> failure = kmp(needle);
        
        int i = 0; int j = 0;
        while(i < haystack.size()){
            if(haystack[i] == needle[j]){
                i++; j++;
            }
            else{
                if(failure[j] == 0){
                    i -= j; j = 0;
                    i++;
                }
                else{
                    j = failure[j - 1];
                }
            }
            
            if(j == needle.size()){
                return i - j;
            }
        }
        return -1;
    }
    
    vector<int> kmp(string needle){
        vector<int> ret(needle.size(), 0);
        if(needle.size() < 2){ return ret; }
        int i = 0; int j = 1;
        while(j < needle.size()){
            if(needle[i] == needle[j]){
                ret[j] = ret[j - 1] + 1;
                i++; j++;
            }
            else{
                i = 0; j++;
            }
        }
        return ret;
    }
};

/*
意外聽說一個叫 Sunday 的解法
照理說還是要更快才對但是還是沒有，倒是用的 memory beat 100%
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        map<char, int> mapping;
        for(int k = 0; k < needle.size(); k++){
            mapping[needle[k]] = k;
        }
        while(i <= haystack.size()){
            if(j == needle.size()){
                return i - j;
            }
            
            if(haystack[i] == needle[j]){
                i++; j++;
            }
            else{
                i = i - j + needle.size();
                j = 0;
                if(i >= haystack.size()){ break; }
                
                if(mapping.count(haystack[i]) == 1){
                    i = i - mapping[haystack[i]];
                }
                else{ i++; }
            }
        }
        return -1;
    }
};