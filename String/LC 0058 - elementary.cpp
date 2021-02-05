/*
58. Length of Last Word
*/

class Solution {
public:
    
    bool isAlpha(const char c){
        return (c >= 'a' && c <='z') || (c >='A' && c<='Z');
    }
    
    int lengthOfLastWord(string s) {
        int ctr =0 ;
        bool flag = false;
        for(int i=s.size()-1;i>=0;i--){
            if(isAlpha(s[i])){
                ctr ++;
                flag = true;
            }
            else if(flag)
                return ctr;
        }
        return ctr;
    }
};