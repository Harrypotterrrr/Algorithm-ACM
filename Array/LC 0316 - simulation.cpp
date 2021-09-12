/*
316. Remove Duplicate Letters
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        vector<bool>visited(26, false);
        vector<int>ctr(26, 0);
        for(auto &i: s) ctr[i-'a'] ++;
        for(auto &i: s){
            ctr[i-'a'] --;
            if(visited[i-'a']) continue;
            while(ans.size() && i < ans.back() && ctr[ans.back()-'a']){
                visited[ans.back()-'a'] = false;
                ans.pop_back();
            }
            ans += i;
            visited[i-'a'] = true;
        }
        
        return ans;
    }
};