/*
485. Max Consecutive Ones
*/

// Solution 1:

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, ctr = 0;
        for(auto &i: nums){
            ctr = (i == 0) ? 0 : ctr + 1;
            ans = ans > ctr ? ans : ctr;
        }
        return ans;
    }
};

// Solution 2:

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, sum = 0;
        for(auto &i: nums){
            sum = (sum + i) * i;
            ans = ans > sum ? ans : sum;
        }
        return ans;
    }
};