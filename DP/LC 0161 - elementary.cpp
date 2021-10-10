/*
161. One Edit Distance
*/

// Solution 1: DP TLE

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1 ; i<=n ; i++) dp[i][0] = i;
        for(int j=1 ; j<=m ; j++) dp[0][j] = j;
        
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                dp[i][j] = s[i-1] == t[j-1] ? dp[i-1][j-1] : min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
            }
        }
        return dp[n][m] == 1;    
    }
};

// Solution 2: one traverse O(n)

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.size() < t.size()) swap(s, t);
        int n = s.size(), m = t.size();
        if(n - m > 1) return false;
        if(n - m == 1){
            for(int i=0 ; i<m ; i++){
                if(s[i] != t[i]){
                    for(int j=i ; j<m ; j++)
                        if(s[j+1] != t[j])
                            return false;
                    return true;
                }
            }
            return true;
        }
        else{
            int ctr = 0;
            for(int i=0 ; i<n ; i++)
                if(s[i] != t[i]) ctr++;
            return ctr == 1;
        }
    }
    
};

// Solution 3:

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size(), m = t.size();
        for(int i=0 ; i<min(n, m) ; i++){
            if(s[i] != t[i]){
                if(n > m) return s.substr(i+1) == t.substr(i);
                else if(n < m) return s.substr(i) == t.substr(i+1);
                else return s.substr(i+1) == t.substr(i+1);
            }
        }
        return abs(n - m) == 1;
    }
};
