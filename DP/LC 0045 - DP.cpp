/************************************************
Problem: 		45. Jump Game II
Algorithm: 		Dynamic Programming, Greedy
Difficulty: 	**
Importance:		***
Remark:			
*************************************************/

// Solution 1: DP TLE O(n^2)

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>ans(nums.size(), INT_MAX);
        ans[0] = 0;
        for(int i=0 ; i<nums.size(); i++) {
            for(int j=i+1 ; j<nums.size() && j <= nums[i] + i ; j++)
                ans[j] = min(ans[j], ans[i] + 1);
        }
        return ans[nums.size()-1];
    }
};

// Solution 2: Greedy O(n)

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int cur = 0, maxn = 0, ans = 0;
        while(maxn < n-1){
            int tmp = maxn;
            for(int i=cur ; i<=tmp && i<n ; i++){
                maxn = maxn > i + nums[i] ? maxn : i + nums[i];
            }
            cur = tmp + 1;
            ans ++;
        }
        return ans;
    }
};