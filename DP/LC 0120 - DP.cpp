/*
120. Triangle
*/

// Solution 1: allocate n*n vector

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        auto n = triangle.size();
        auto m = triangle[n-1].size();
        vector<vector<int>>dp(n, vector<int>(m, 0));
        
        dp[0][0] = triangle[0][0];
        for(int i=1; i <n ; i++){
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            for(int j=1 ; j<triangle[i].size()-1 ; j++){
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
            }
            dp[i][triangle[i].size()-1] += dp[i-1][triangle[i-1].size()-1;
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};


// Solution 2: allocate 2*n vector

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        vector<vector<int>>dp(2, vector<int>(triangle[triangle.size()-1].size(), 0));
        
        bool tag = 0;
        dp[tag][0] = triangle[0][0]; tag = !tag;
        
        for(int i=1 ; i<triangle.size() ; i++){
            dp[tag][0] = dp[!tag][0] + triangle[i][0];
            dp[tag][triangle[i].size()-1] = dp[!tag][triangle[i].size()-2] + triangle[i][triangle[i].size()-1];
            for(int j=1 ; j<triangle[i].size()-1 ; j++){
                dp[tag][j] = triangle[i][j] + min(dp[!tag][j], dp[!tag][j-1]);
            }
            tag = !tag;
        }
        return *min_element(dp[!tag].begin(), dp[!tag].end());
    }
};


// Solution 3: inversed dp

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        vector<int>dp(triangle.back());
        
        for(int i=triangle.size()-2 ; i>=0 ; i--){
            for(int j=0 ; j<=i ; j++)
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
        }
        
        return dp[0];

    }
};