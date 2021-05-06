/*
189. Rotate Array
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>tmp(nums.begin(), nums.end());
        int len = nums.size();
        for(int i=0 ; i<nums.size() ; i++){
            nums[(i+k)%len] = tmp[i];
        }
    }
};


// Solution 2: optimize space complexity

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if((k %= n) == 0)
            return;
        int cur = 0 , pre=nums[0], start = 0;
        for(int i=0 ; i<nums.size() ; i++){
            swap(nums[(cur+k) % n], pre);
            cur = (cur + k) % n;
            if(cur == start){
                start++;
                pre = nums[start];
                cur = start;
            }
        }
        return;
    }
};

// Solution 3: IQ swap

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if((k %= n) == 0)
            return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        return;
    }
};