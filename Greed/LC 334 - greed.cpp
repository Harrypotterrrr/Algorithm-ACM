/*
334. Increasing Triplet Subsequence
*/

// Solution 1: TLE DP

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 0);
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j< i ; j++){
                if(nums[i] > nums[j])
                    dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
            }
            if(dp[i] >= 2) return true;
        }
        return false;
    }
};

// Solution 2: Greed

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for(auto &i : nums){
            if(i < first) first = i;
            else if(i > first && i < second) second = i;
            else if(i > second) return true;
        }
        return false;
    }
};

// Solution 3: more elegant

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for(auto &i : nums){
            if(i <= first) first = i;
            else if(i <= second) second = i;
            else return true;
        }
        return false;
    }
};

// Solution 4: Good solution, memory array to record the increasing and decreasing adjacent value

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int>inc(n);
        vector<int>dec(n);
        dec[0] = nums[0];
        inc[n-1] = nums[n-1];
        for(int i=1 ; i<n ; i++) dec[i] = nums[i] < dec[i-1] ? nums[i] : dec[i-1];
        for(int i=n-2 ; i>=0 ; i--) inc[i] = nums[i] > inc[i+1] ? nums[i] : inc[i+1];
        for(int i=1 ; i<n-1 ; i++){
            if(nums[i] > dec[i] && nums[i] < inc[i])
                return true;
        }
        return false;
    }
};