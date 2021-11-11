/************************************************
Problem: 		1231. Divide Chocolate
Algorithm: 		Dynamic Programming, Binary Search
Difficulty: 	***
Importance:		*****
Remark:			min-max problem, similar to LC 0410
*************************************************/

// Solution 1: Dynamic Programming O(n^2m)

class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int m) {
        int n = sweetness.size();
        vector<vector<int>> dp(m+2, vector<int>(n+1, 0));
        vector<int> summ(n+1, 0);
        for(int i=0 ; i<n ; i++) summ[i+1] = summ[i] + sweetness[i];
        for(int i=0 ; i<n+1 ; i++) dp[0][i] = INT_MAX;

        for(int j=1 ; j<=m+1 ; j++){
            for(int i=j ; i<=n ; i++){
                for(int k=j-1 ; k<=i-1 ; k++){
                    dp[j][i] = max(dp[j][i], min(dp[j-1][k], summ[i] - summ[k]));
                }
            }
        }
        return dp[m+1][n];
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