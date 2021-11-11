/************************************************
Problem: 		410. Split Array Largest Sum
Algorithm: 		Dynamic Programming, Binary Search
Difficulty: 	***
Importance:		*****
Remark:			min-max problem
*************************************************/

// Solution 1: Dynamic Programming O(n^2m)

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1 ; i<=n ; i++) dp[1][i] = dp[1][i-1] + nums[i-1];
        
        for(int i=2 ; i<=m ; i++){
            for(int j=i ; j<=n ; j++){
                int minn = INT_MAX, cur;
                for(int k=i-1 ; k<=j-1 ; k++){
                    cur = max(dp[i-1][k], dp[1][j] - dp[1][k]);
                    minn = minn < cur ? minn : cur;
                }
                dp[i][j] = minn;
            }
        }

        return dp[m][n];
    }
};

// Solution 2: change a little bit of solution 1

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, INT_MAX));
        vector<int> sub(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k < i; k++) {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        return f[n][m];
    }
};

// Solution 3: Binary search + Greedy O(nlog(sum(nums)))

class Solution {
public:
    int n;
    int splitArray(vector<int>& nums, int m) {
        n = nums.size();
        int left = INT_MIN, right = 0;
        for(auto &i: nums) {
            left = left > i ? left : i;
            right += i;
        }
        while(left < right){
            int mid = ((right - left) >> 1) + left;
            if(min_groups(nums, mid, m)) right = mid;
            else left = mid+1;
        }
        return left;
    }
    
    bool min_groups(vector<int>& nums, int lower, int m){
        int cur_sum = 0, ctr = 1;
        for(int i=0 ; i<n ; i++){
            cur_sum += nums[i];
            if(cur_sum > lower){
                cur_sum = nums[i];
                ctr++;
                if(ctr > m) return false;
            }
        }
        return true;
    }
};