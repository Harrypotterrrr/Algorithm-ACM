/*
14. Longest Common Prefix
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int cur = 0;
        while(true){
            char tmp = strs[0][cur];
            int i = 0;
            for(i; i<strs.size() ; i++){
                if(cur >= strs[i].size())
                    break;
                if(strs[i][cur] != tmp)
                    break;
            }
            if(i == strs.size())
                ans += tmp;
            else
                break;
            cur++;
        }
        return ans;
        
    }
};