/*
16. 3Sum Closest

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include "../include/include.h"

class Solution {
public:
    
    
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int minn = INT_MAX, ans, sum;
        for(int i=0 ; i<nums.size() ; i++){
            int begin=i+1, end = nums.size()-1;
            while(begin < end){
                sum = nums[begin] + nums[end] + nums[i];
                if(sum == target) return target;
                
                if(minn > abs(target - sum)){
                    minn = abs(target - sum);
                    ans = sum;
                }
                if(sum < target) begin++;
                else if(sum > target) end--;

                while(begin < end && begin > 1 && nums[begin] == nums[begin - 1]) begin++;
                while(begin < end && end < nums.size()-1 && nums[end] == nums[end+1]) end--;
            }
            while(i < nums.size() - 1 && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        int ret = Solution().threeSumClosest(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
