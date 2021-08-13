/*
132. Palindrome Partitioning II
*/

// Solution 1: TLE dp O(n^3)

class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> flag(s.size(), vector<bool>(s.size(), false));
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        
        // cout<<s.size()<<endl;
        for(int i=0 ; i<s.size() ; i++){
            for(int j=0 ; j<s.size()-i ; j++){
                if(s[j] == s[i+j] && (i<=2 || flag[j+1][i+j-1])){
                    flag[j][i+j] = true;
                    dp[j][i+j] = 0;
                    continue;
                }
                int summ = INT_MAX;
                for(int k=j ; k<i+j ; k++){
                    int tmp = dp[j][k] + dp[k+1][i+j];
                    summ = summ < tmp ? summ : tmp;
                }
                dp[j][i+j] = summ + 1;
            }
        }
        return dp[0][s.size() - 1];
    }
};

// Solution 2: DP O(n^2), iterate non-diagonally

class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> flag(s.size(), vector<bool>(s.size(), false));
        vector<int> dp(s.size(), 0);
        
        for(int i=0 ; i<s.size() ; i++){
            dp[i] = i;
            for(int j=0 ; j<=i ; j++){
			// for(int j=i ; j>=0 ; j--) // both ok
                if(s[j] == s[i] && (i - j <= 2 || flag[j+1][i-1])){
                    flag[j][i] = true;
                    if(j == 0)
                        dp[i] = 0;
                    else
                        dp[i] = dp[i] < dp[j-1] + 1 ? dp[i] : dp[j-1] + 1;
                }
            }
        }
        return dp[s.size() - 1];
    }
};

// Solution 3: reversed version of solution 2

class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> flag(s.size(), vector<bool>(s.size(), false));
        vector<int> dp(s.size(), 0);
        
        for(int i=s.size()-1 ; i>=0 ; i--){
            dp[i] = s.size() - i + 1;
            for(int j=s.size()-1 ; j>= i ; j--){
            // for(int j=i ; j<s.size() ; j++){ // both ok
                if(s[i] == s[j] && (j - i <= 2 || flag[i+1][j-1])){
                    flag[i][j] = true;
                    if(j == s.size() - 1)
                        dp[i] = 0;
                    else
                        dp[i] = dp[i] < dp[j+1] + 1 ? dp[i] : dp[j+1] + 1;
                }
            }
        }
        return dp[0];
    }
};


// Solution 4: best solution, use the property of prolindrome: symmetic

class Solution {
public:
    int minCut(string s) {
        vector<int> dp(s.size()+1, INT_MAX);
        dp[0] = -1;
        for(int i=0 ; i<s.size() ; i++){
            for(int len=0 ; i-len >= 0 && i+len < s.size() && s[i-len] == s[i+len] ; len++){
                dp[i+len+1] = min(dp[i+len+1], dp[i-len] + 1); 
            }
            for(int len=0 ; i-len >= 0 && i+len+1 < s.size() && s[i-len] == s[i+len+1]; len++){
                dp[i+len+2] = min(dp[i+len+2], dp[i-len] + 1);
            }
        }
        return dp[s.size()];
    }
};
