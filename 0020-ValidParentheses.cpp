/*
很簡單的練習用 stack 的題目
一開始想說用 map 會不會看起來比較優美
但果然還是用條件判斷比較快 = =
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> para;
        para.push('.');
        
        for(int i = 0; i < s.size(); i++){
            switch(s[i]){
                case '(': case '{': case '[':
                    para.push(s[i]);
                    break;
                case ')':
                    if(para.top() == '('){ para.pop(); }
                    else{ return false; }
                    break;
                case '}':
                    if(para.top() == '{'){ para.pop(); }
                    else{ return false; }
                    break;
                case ']':
                    if(para.top() == '['){ para.pop(); }
                    else{ return false; }
                    break;
            }
        }
        if(para.top() == '.'){ return true; }
        else{ return false; }
    }
};