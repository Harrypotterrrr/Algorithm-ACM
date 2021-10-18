/*
689. Maximum Sum of 3 Non-Overlapping Subarrays
Array, PrefixSum, Dynamic Programming
*/

// Solution 1: left and right prefix

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(3);
        vector<int> prefix(n-k+1, 0), left(n-k+1, 0), right(n-k+1, 0);
        for(int i=0 ; i<k ; i++) prefix[0] += nums[i];
        for(int i=1 ; i<=n-k ; i++) prefix[i] = prefix[i-1] + nums[i+k-1] - nums[i-1];
        
        int left_max = INT_MIN, right_max = INT_MIN;
        for(int i=0 ; i<=n-k ; i++){
            if(left_max < prefix[i]){
                left_max = prefix[i];
                left[i] = i;
            }
            else
                left[i] = left[i-1];
        }
        for(int i=n-k ; i>=0 ; i--){
            if(right_max <= prefix[i]){
                right_max = prefix[i];
                right[i] = i;
            }
            else
                right[i] = right[i+1];
        }
        int sum_max = INT_MIN;
        for(int i=k ; i<=n-(k<<1) ; i++){
            int tmp = prefix[i] + prefix[left[i-k]] + prefix[right[i+k]];
            if(sum_max < tmp){
                sum_max = tmp;
                ans = {left[i-k], i, right[i+k]};
            }
        }
        return ans;
    }
};