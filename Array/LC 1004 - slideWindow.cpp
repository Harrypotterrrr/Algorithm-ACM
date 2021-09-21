/*
1004. Max Consecutive Ones III
*/


// Solution 1: sliding windows

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, ans = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == 1 || k){
                ans = ans > i - left + 1? ans : i - left + 1;
                k = (nums[i] == 0) ? k - 1 : k;
            }
            else{
                while(nums[left])
                    left++;
                left++;
            }
        }
        return ans;
    }
};

// Solution 2: Genius sliding windows\

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size(), i = 0, j = 0;
        for (; j < n; ++j) {
            if (nums[j] == 0) --k;
            if (k < 0 && nums[i++] == 0) ++k;
        }
        return j - i;
    }
};