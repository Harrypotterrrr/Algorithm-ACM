/*
516. Longest Palindromic Subsequence
*/

// Solution 1: dp, space and time are both O(n^2)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i=0 ; i<s.size() ; i++){
            for(int j=0 ; j<s.size() - i ; j++){
                if(i == 0)
                    dp[j][j] = 1;
                // else if(i == 1){
                //     if(s[j] == s[j+i])
                //         dp[j][i+j] = 2;
                //     else
                //         dp[j][i+j] = 1;

                // }
				// Above not necessary bcz 2-d dp, dp[1][0] = 0 though meaningless
                else if(s[j] == s[j+i]){
                    dp[j][i+j] = dp[j+1][i+j-1] + 2;
                }
                else{
                    dp[j][i+j] = max(dp[j+1][i+j], dp[j][i+j-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};

// Solution 2: much similar to solution 1 except iterate vertically

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i=0 ; i<s.size() ; i++){
            for(int j=i ; j>=0 ; j--){
                if(i == j)
                    dp[i][i] = 1;
                
                else if(s[j] == s[i]){
                    dp[j][i] = dp[j+1][i-1] + 2;
                }
                else{
                    dp[j][i] = max(dp[j+1][i], dp[j][i-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};

// Solution 3: optimization of solution 2, space O(n)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(2, vector<int>(s.size(), 0));
        bool flag = false;
        for(int i=0 ; i<s.size() ; i++){
            for(int j=i ; j>=0 ; j--){
                if(i == j)
                    dp[flag][j] = 1;
                
                else if(s[j] == s[i]){
                    dp[flag][j] = dp[!flag][j+1] + 2;
                }
                else{
                    dp[flag][j] = max(dp[flag][j+1], dp[!flag][j]);
                }
            }
            flag = !flag;
        }
        return dp[!flag][0];
    }
};

// Solution 4: recursion way

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), 0));
        return solve(s, memo, 0, s.size()-1);
    }
    
    int solve(string &s, vector<vector<int>>& memo, int start, int end){
        if(start > end)
            return 0;
        if(memo[start][end])
            return memo[start][end];
        if(start == end){
            return memo[start][end] = 1;
        }
        if(s[start] == s[end]){
            solve(s, memo, start+1, end-1);
            return memo[start][end] = memo[start+1][end-1] + 2;
        }
        else{
            solve(s, memo, start+1, end);
            return memo[start][end] = max(solve(s, memo, start+1, end), solve(s, memo, start, end-1));
        }
    }
};
