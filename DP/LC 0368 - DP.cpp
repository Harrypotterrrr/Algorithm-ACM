/************************************************
Problem: 		368. Largest Divisible Subset
Algorithm: 		Dynamic Programming, DFS, Search
Difficulty: 	**
Importance:		**
Remark:			
*************************************************/

// Solution 1: DP O(N^2), space O(N)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums;
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> dp(n);
        for(int i=0 ; i<n ; i++) dp[i] = {1, i};
        int maxn = 1, maxn_arg = 0;
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(nums[i] % nums[j] == 0 && dp[j].first + 1 > dp[i].first)
                    dp[i] = {dp[j].first + 1, j};
            }
            if(maxn < dp[i].first){
                maxn = dp[i].first;
                maxn_arg = i;
            }
        }
        vector<int>ans;
        int i = maxn_arg;
        while(i != dp[i].second){
            ans.push_back(nums[i]);
            i = dp[i].second;
        }
        ans.push_back(nums[i]);
        return ans;
    }
};

// Solution 2: get ans array with a little optimization, similar to solution 1

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums;
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> dp(n);
        for(int i=0 ; i<n ; i++) dp[i] = {1, i};
        int maxn = 1, maxn_arg = 0;
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(nums[i] % nums[j] == 0 && dp[j].first + 1 > dp[i].first)
                    dp[i] = {dp[j].first + 1, j};
            }
            if(maxn < dp[i].first){
                maxn = dp[i].first;
                maxn_arg = i;
            }
        }
        vector<int>ans;
        for(int i=0 ; i<maxn ; i++){
            ans.push_back(nums[maxn_arg]);
            maxn_arg = dp[maxn_arg].second;
        }
        return ans;
    }
};

// Solution 3: DFS + memorization O(N^2), space O(N)

class Solution {
public:
    
    int n;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        n = nums.size();
        if(n == 1) return nums;
        sort(nums.begin(), nums.end());
        vector<pair<int, int>>memo(n, {-1, -1});
        
        int maxn = 1, maxn_id = 0;
        for(int i=0 ; i<n ; i++){
            int tmp = dfs(memo, nums, i);
            if(maxn < tmp){
                maxn = tmp;
                maxn_id = i;
            }
        }
        vector<int>ans;
        for(int i=0 ; i<maxn ; i++){
            ans.push_back(nums[maxn_id]);
            maxn_id = memo[maxn_id].second;
        }
        return ans;
    }
    
    int dfs(vector<pair<int, int>> &memo, vector<int> &nums, int k){
        if(k >= n) return 0;
        if(memo[k].first != -1) return memo[k].first; // -1
        int maxn = 1, maxn_id = k;
        for(int i=k+1 ; i<n ; i++){
            if(nums[i] % nums[k] == 0){
                int tmp = dfs(memo, nums, i) + 1;
                if(maxn < tmp){
                    maxn = tmp;
                    maxn_id = i;
                }
            }
        }
        memo[k] = {maxn, maxn_id};
        return maxn;
    }
};