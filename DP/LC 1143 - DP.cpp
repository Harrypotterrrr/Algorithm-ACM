/*
1143. Longest Common Subsequence
*/

// Solution 1: TLE recursion

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, 0, text2, 0);
    }
    int solve(string& s1, int p1, string &s2, int p2){
        if(p1 >= s1.size() || p2 >= s2.size())
            return 0;
        if(s1[p1] == s2[p2])
            return 1 + solve(s1, p1+1, s2, p2+1);
        return max(solve(s1, p1+1, s2, p2), solve(s1, p1, s2, p2+1));
    }
};

// Solution 2: memorization to optimize solution 1

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), 0));
        return solve(memo, text1, 0, text2, 0);
    }
    int solve(vector<vector<int>>&memo, string& s1, int p1, string &s2, int p2){
        if(p1 >= s1.size() || p2 >= s2.size())
            return 0;
        if(memo[p1][p2])
            return memo[p1][p2];
        if(s1[p1] == s2[p2])
            return memo[p1][p2] = 1 + solve(memo, s1, p1+1, s2, p2+1);
        return memo[p1][p2] = max(solve(memo, s1, p1+1, s2, p2), solve(memo, s1, p1, s2, p2+1));
    }
};

// Solution 3: dp

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        
        for(int i=0 ; i<text1.size() ; i++){
            for(int j=0 ; j<text2.size() ; j++){
                if(text1[i] == text2[j])
                    dp[i+1][j+1] = dp[i][j] + 1;
                else
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }

        return dp[text1.size()][text2.size()];
    }

};

// Solution 4: space optimization of solution 3

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(2, vector<int>(text2.size()+1, 0));
        bool flag = false;
        for(int i=0 ; i<text1.size() ; i++){
            for(int j=0 ; j<text2.size() ; j++){
                if(text1[i] == text2[j])
                    dp[flag][j+1] = dp[!flag][j] + 1;
                else
                    dp[flag][j+1] = max(dp[flag][j], dp[!flag][j+1]);
            }
            flag = !flag;
        }

        return dp[!flag][text2.size()];
    }

};