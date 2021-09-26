/*
75. Sort Colors
*/

// Solution 1: two pass

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>ctr(3, 0);
        for(auto &i: nums){
            ctr[i] ++;
        }
        for(int i=0, k=0 ; i<3 ; i++){
            while(ctr[i]){
                nums[k++] = i;
                ctr[i]--;
            }
        }
    }
};

// Solution 2: one pass

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        for(int i=0 ; i<nums.size() ;){
            if(nums[i] == 0){
                swap(nums[i], nums[left]);
                left++;
                i++;
            }
            else if(nums[i] == 2){
                swap(nums[i], nums[right]);
                right--;
            }
            else{
                i++;
            }
        }
    }
};

// Solution 3: while instead of for, same to solution 2

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, cur = 0;
        while(cur <= right){
            if(nums[cur] == 2){
                swap(nums[cur], nums[right--]);
            }
            else if(nums[cur] == 0){
                swap(nums[cur++], nums[left++]);
            }
            else
                cur++;
        }
    }
};