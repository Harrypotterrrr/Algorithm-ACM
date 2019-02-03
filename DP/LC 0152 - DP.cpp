/*
152. Maximum Product Subarray

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

#include"../include/include.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxn, minn;
        int t_maxn, t_minn;
        maxn = minn = t_maxn = t_minn = nums[0];
        for(auto i=1 ; i<nums.size(); i++){
            if(nums[i] > 0){
                int tmp = t_maxn * nums[i];
                t_maxn = max(nums[i], tmp);
                t_minn = t_minn * nums[i];
                maxn = max(maxn, t_maxn);
            }
            else if(nums[i] < 0){
                int tmp = t_maxn * nums[i];
                t_maxn = t_minn * nums[i];
                t_minn = min(nums[i], tmp);
                maxn = max(maxn, t_maxn);
            }
            else{
                t_maxn = t_minn = 0;
            }
        }
        return maxn;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().maxProduct(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}