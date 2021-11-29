/************************************************
Problem: 		1937. Maximum Number of Points with Cost
Algorithm: 		Dynamic Programming
Difficulty: 	***
Importance:		*****
Remark:			
*************************************************/

// Solution 1: TLE O(n*m*m)

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        int ans = 0;
        vector<vector<int>> dp(n+1, vector(m, 0));
        for(int i=1 ; i<=n ; i++){
            for(int j=0 ; j<m ; j++){
                for(int k=0 ; k<m ; k++)
                    dp[i][j] = max(dp[i][j], dp[i-1][k] - abs(k-j));
	            dp[i][j] += points[i-1][j];
                ans = ans > dp[i][j] ? ans : dp[i][j];
            }
        }
        return ans;
    }
};


// Solution 2: optimize time complexity, O(nm)
// reference: https://leetcode.com/problems/maximum-number-of-points-with-cost/discuss/1344888/C%2B%2B-dp-from-O(m-*-n-*-n)-to-O(m-*-n)

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        long long ans = 0;
        vector<vector<long long>> dp(n+1, vector<long long>(m, 0));
        for(int i=1 ; i<=n ; i++){
            vector<long long>left_max(m, 0);
            vector<long long>right_max(m, 0);
            left_max[0] = dp[i-1][0];
            right_max[m-1] = dp[i-1][m-1] - m + 1;
            for(int j=1 ; j<m ; j++) left_max[j] = max(left_max[j-1], dp[i-1][j] + j);
            for(int j=m-2 ; j>=0 ; j--) right_max[j] = max(right_max[j+1], dp[i-1][j] - j);
            for(int j=0 ; j<m ; j++){
                dp[i][j] = max(left_max[j] - j, right_max[j] + j);
	            dp[i][j] += points[i-1][j];
                ans = ans > dp[i][j] ? ans : dp[i][j];
            }
        }
        return ans;
    }
};
