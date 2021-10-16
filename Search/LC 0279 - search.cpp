/*
279. Perfect Squares
DFS, BFS, Dynamic Programming, Math
*/

// Solution 1: dfs with memorization array

class Solution {
public:
    
    vector<vector<int>>memo;

    int numSquares(int n) {
        vector<int>sq;
        for(int i=1 ; i*i<=n ; i++) sq.push_back(i*i);
        memo.resize(n + 1, vector<int>(sq.size(), -1));
        return dfs(n, sq, sq.size()-1);
    }
    int dfs(int n, vector<int>&sq, int k){
        if(k < 0) return INT_MAX;
        if(n - sq[k] == 0) return memo[n][k] = 1;
        if(memo[n][k] != -1) return memo[n][k];
        int rtn = INT_MAX, rtn2 = INT_MAX;
        if(n - sq[k] > 0) rtn = dfs(n-sq[k], sq, k) + 1;
        rtn2 = dfs(n, sq, k-1);
        return memo[n][k] = rtn < rtn2 ? rtn : rtn2;
    }
};

// Solution 2: two-dimensional dp

class Solution {
public:
    

    int numSquares(int n) {
        vector<int>sq;
        for(int i=1 ; i*i<=n ; i++) sq.push_back(i*i);
        vector<vector<int>>dp(n + 1, vector<int>(sq.size(), INT_MAX));
        for(int i=0 ; i<sq.size() ; i++) dp[0][i] = 0;
        for(int i=1 ; i<=n ; i++) dp[i][0] = dp[i-1][0] + 1;
        int tmp;
        for(int i=1 ; i<sq.size() ; i++){
            for(int j=1 ; j<=n ; j++){
                if(j >= sq[i] ) tmp = min(dp[j-sq[i]][i] + 1, dp[j][i-1]);
                else tmp = dp[j][i-1];
                dp[j][i] = dp[j][i] < tmp ? dp[j][i] : tmp;
            }
        }
        return dp[n][sq.size()-1];
    }
};

// Solution 3: one-dimensional dp

class Solution {
public:
    
    int numSquares(int n) {
        vector<int>sq;
        for(int i=1 ; i*i<=n ; i++) sq.push_back(i*i);
        vector<int>dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=0 ; i<sq.size() ; i++){
            for(int j=1; j<=n ; j++){
                int tmp;
                if(j >= sq[i]) tmp = dp[j-sq[i]] + 1 < dp[j] ? dp[j-sq[i]] + 1 : dp[j];
                else tmp = dp[j];
                dp[j] = dp[j] < tmp ? dp[j] : tmp;
            }
        }
        return dp[n];
    }
};

// Solution 4: one-dimensional dp, no pre-calculated vector 

class Solution {
public:

    int numSquares(int n) {
        vector<int>dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=1 ; i * i<=n ; i++){
            for(int j=1; j<=n ; j++){
                int tmp;
                if(j >= i*i) tmp = dp[j-i*i] + 1 < dp[j] ? dp[j-i*i] + 1 : dp[j];
                else tmp = dp[j];
                dp[j] = dp[j] < tmp ? dp[j] : tmp;
            }
        }
        return dp[n];
    }
};

// Soution 5: one-dimensional dp, another way of solution 4

class Solution {
public:
    

    int numSquares(int n) {
        vector<int>dp(n+1, INT_MAX);
        dp[0] = 0;
        
        for(int i=1; i<=n ; i++){
            for(int j=1 ; j*j<=n ; j++){
                if(i < j * j) break;
                dp[i] = dp[i] < dp[i-j*j] + 1 ? dp[i] : dp[i-j*j] + 1;
            }
        }
        return dp[n];
    }
};

// Solution 6: bfs + set

class Solution {
public:
    int numSquares(int n) {
        queue<int>Q({n});
        unordered_set<int>uS;
        int level = 0;
        while(!Q.empty()){
            level ++;
            for(int i=Q.size()-1 ; i>=0 ; i--){
                int cur = Q.front() ; Q.pop(); uS.erase(cur);
                for(int j=1; j*j<=cur ; j++){
                    if(cur - j*j == 0) return level;
                    if(uS.find(cur-j*j) == uS.end())
                        Q.push(cur-j*j);
                }
            }
        }
        return -1;
    }
};

// Solution 7: complicated Math

class Solution {
public:
    int numSquares(int n) {
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        for (int a = 0; a * a <= n; ++a) {
            int b = sqrt(n - a * a);
            if (a * a + b * b == n) {
                return !!a + !!b;
            }
        }
        return 3;
    }
};