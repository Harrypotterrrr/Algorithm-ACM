/*
647. Palindromic Substrings
*/

// Solution 1: TLE dfs

class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() <= 0 )
            return 0;
        vector<vector<bool>>flag(s.size(), vector<bool>(s.size(), false));
        for(int i=0 ; i<s.size() ; i++){
            for(int j=0 ; j<s.size() - i ; j++){
                if(s[j] == s[i+j] && (i <= 2 || flag[j+1][i+j-1]))
                    flag[j][i+j] = true;
            }
        }
        return solve(s, flag, 0);
    }
    
    int solve(string &s, vector<vector<bool>> &flag, int start){
        if(start >= s.size())
            return 0;
        int ctr = 0;
        for(int i=start ; i<s.size(); i++){
            ctr += solve(s, flag, i+1);
            if(flag[start][i]){
                ctr++;
                flag[start][i] = false;
            }
        }
        return ctr;
    }
    
};

// Solution 2: use visit to pruning

class Solution {
public:
    int countSubstrings(string s) {
    
        if(s.size() <= 0 )
            return 0;
        vector<vector<bool>>flag(s.size(), vector<bool>(s.size(), false));
        vector<vector<bool>>visit(s.size(), vector<bool>(s.size(), false));
        for(int i=0 ; i<s.size() ; i++){
            for(int j=0 ; j<s.size() - i ; j++){
                if(s[j] == s[i+j] && (i <= 2 || flag[j+1][i+j-1]))
                    flag[j][i+j] = true;
            }
        }
        return solve(s, flag, visit, 0);
    }
    
    int solve(string &s, vector<vector<bool>> &flag, vector<vector<bool>> &visit, int start){
        if(start >= s.size())
            return 0;
        
        int ctr = 0;
        for(int i=s.size()-1 ; i>=start ; i--){
            if(flag[start][i]){
                ctr++;
            }
            if(i<s.size()-1 && !visit[i+1][s.size()-1])
                ctr += solve(s, flag, visit, i+1);
        }

        visit[start][s.size() - 1] = true;
        return ctr;
    }
    
};
