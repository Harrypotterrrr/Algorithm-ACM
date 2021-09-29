/*
922. Sort Array By Parity II
*/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int odd = 1, even = 0;
        while(odd < nums.size() && even < nums.size()){
            while(odd < nums.size() && nums[odd] % 2 == 1)
                odd += 2;
            while(even < nums.size() && nums[even] % 2 == 0)
                even += 2;
            if(odd >= nums.size() && even >= nums.size())
                break;
            swap(nums[even], nums[odd]);
            even += 2;
            odd += 2;
        }
        return nums;
    }
};