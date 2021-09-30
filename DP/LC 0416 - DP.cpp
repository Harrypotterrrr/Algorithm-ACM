/*
416. Partition Equal Subset Sum
*/

// Solution 1: dfs + memo

class Solution {
public:
    
    int n, sum = 0;
    vector<vector<bool>>memo;
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        for(auto& i: nums) sum += i;
        if(sum % 2) return false;
        memo.resize(n, vector<bool>((sum >> 1) + 1, false));
        return solve(nums, 0, 0);
    }
    
    bool solve(vector<int>& nums, int k, int cur){
        if(cur == sum >> 1) return true;
        if(k >= n || cur > sum >> 1) return false;
        if(memo[k][cur]) return false;
        
        bool flag = solve(nums, k+1, cur+nums[k]) || solve(nums, k+1, cur);
        memo[k][cur] = true;
        return flag;
    }
};

// Solution 2: DP

class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
    	int n, sum = 0;
        n = nums.size();
        for(auto& i: nums) sum += i;
        if(sum % 2) return false;
        
        vector<vector<bool>>dp(n+1, vector<bool>((sum >> 1) + 1, false));
        dp[0][0] = true;
        for(int i=0 ; i<=sum>>1 ; i++){
            for(int j=1 ; j<=n ; j++){
                dp[j][i] = dp[j-1][i] || (i >= nums[j-1] ? dp[j-1][i-nums[j-1]] : false);
            }
        }
        return dp[n][sum>>1];
    }
};

// Solution 3: DP in another order of num and n

class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n, sum = 0;
        n = nums.size();
        for(auto& i: nums) sum += i;
        if(sum % 2) return false;
        sum >>= 1;
        
        vector<vector<bool>>dp(n+1, vector<bool>(sum + 1, false));
        dp[0][0] = true;
        
        for(int i=1 ; i<=n ; i++){
            int curr = nums[i-1];
            for(int j=1 ; j<=sum ; j++){
                dp[i][j] = dp[i-1][j] || ( j-curr >= 0 ? dp[i-1][j-curr] : false );
            }
        }
        return dp[n][sum];
    }
};

// Solution 4: dp with 1-dimension vector

class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n, sum = 0;
        n = nums.size();
        for(auto& i: nums) sum += i;
        if(sum % 2) return false;
        sum >>= 1;
        
        vector<bool>dp(sum + 1, false);
        dp[0] = true;
        
        for(int i=1 ; i<=n ; i++){
            int curr = nums[i-1];
            for(int j=sum ; j>=0 ; j--){
                dp[j] = dp[j] || ( j-curr >= 0 ? dp[j-curr] : false );
            }
        }
        
        return dp[sum];
    }
    

};

// Solution 5: bitset manipulation

class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
    	bitset<20001>bits(1);
        int sum = 0;
        for(auto &i: nums){
            bits |= bits << i;
            sum += i;
        }
        return !(sum % 2) && bits[sum >> 1];
    }
};
