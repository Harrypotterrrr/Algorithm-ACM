/*
905. Sort Array By Parity
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int odd = 0, even = nums.size()-1;
        while(odd <= even){
            while(odd <= even && nums[odd] % 2 == 0) odd++;
            while(even >= odd && nums[even] % 2 == 1) even--;
            if(odd >= even) break;
            swap(nums[odd], nums[even]);
            odd++; even--;
        }
        return nums;
    }
};