/*
14. Longest Common Prefix
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1)
            return strs[0];
        int k = 0;
        while(true){
            char cur = strs[0][k];
            for(int i=1 ; i<strs.size() ; i++){
                if(strs[i][k] != cur || strs[i].size() <= k)
                    return strs[0].substr(0, k);
            }
            k++;
        }
        return strs[0];
    }
};
};