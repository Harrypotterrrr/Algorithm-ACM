/*
45. Jump Game II
*/

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

// Solution 2

class Solution {
public:
    int jump(vector<int>& nums) {
        int max_reach = 0, ctr = 0, i = 0;
        
        while(max_reach < nums.size()-1){
            ctr ++;
            int cur_reach = max_reach;
            for(;i<=cur_reach ; i++)
                max_reach = max(max_reach, nums[i] + i);
            
            if(cur_reach == max_reach)
                return -1;
        }
        return ctr;
    }
};