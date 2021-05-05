/*
41. First Missing Positive
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>S;
        for(int i=0 ; i<nums.size() ; i++)
            if(nums[i] > 0)
                S.insert(nums[i]);
        
        int pre = 1;
        for(auto &i: S){
            if(i != pre){
                return pre;
            }
            pre ++;
        }
        return pre;
    }
};

// Solution 2: IQ, save space complexity

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(auto i=0 ; i <nums.size() ; i++){
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(auto i=0 ; i < nums.size() ; i++)
            if(nums[i] != i + 1)
                return i + 1;
        return nums.size() + 1;
    }
};

// Solution 3: IQ, use index and mod to store the info

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);
        int len = nums.size();
        for(int i=0 ; i<len ; i++){
            if(nums[i] < 0 || nums[i] >= len)
                nums[i] = 0;
        }
        for(int i=0 ; i<len ; i++){
            nums[nums[i] % len] += len;
        }
        for(int i=1 ; i<len ; i++){
            if(nums[i] / len == 0)
                return i;
        }
        return len;
    }
};