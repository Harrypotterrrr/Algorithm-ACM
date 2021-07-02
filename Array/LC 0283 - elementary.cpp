/*
283. Move Zeroes
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> tmp(nums.begin(), nums.end());
        int ctr = 0, j = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(tmp[i] == 0)
                ctr++;
            else
                nums[j++] = tmp[i];
        }
        while(ctr--){
            nums[j++] = 0; 
        }
    }
};

// Solution 2: space optimization

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ctr = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == 0)
                ctr++;
            else
                nums[i-ctr] = nums[i];
        }
        for(int j=nums.size()-ctr ; j<nums.size() ; j++) {
            nums[j] = 0;
        }
    }
};

// Solution 3: swap to optimize

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] != 0){
                swap(nums[i], nums[zero++]);
            }
        }
    }
};
