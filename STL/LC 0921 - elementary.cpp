/*
921. Minimum Add to Make Parentheses Valid
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>S;
        int ans = 0;
        for(auto& i : s){
            if(i == '(') S.push(i);
            else if(S.empty()) ans++;
            else S.pop();
        }
        while(!S.empty()){
            S.pop();
            ans++;
        }
        return ans;
    }
};