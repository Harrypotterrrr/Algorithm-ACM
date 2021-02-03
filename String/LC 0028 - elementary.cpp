/*
28. Implement strStr()
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle.size() == 0)
            return 0;
        for(auto i=0 ; i<haystack.size();i++){
            int j=0, i_cur=i;
            for(; j<needle.size();j++,i_cur++){
                if(i_cur >= haystack.size())
                    return -1;
                if(haystack[i_cur] != needle[j]){
                    break;
                }
            }
            if(j == needle.size())
                return i;
        }
        return -1;
    }
};

// solution 2
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle.size() == 0)
            return 0;
        auto j=0;
        for(auto i=0 ; i<haystack.size();i++){
            if(needle[j] == haystack[i]){
                j++;
            }
            else{
                i-=j;
                j=0;
            }
            
            if(j>=needle.size())
                return i - j +1;
        }
        return -1;
    }
};