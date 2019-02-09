/*
34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

#include "../include/include.h"

class Solution {
public:
    vector<int> searchRange_linearScan(vector<int>& nums, int target) {
        int st = -1, ed = -1;
        for(auto i=0 ; i<nums.size() ; i++)
            if(nums[i] == target){
                if(st == -1) {st = i; ed = i;}
                else ed++;
            }
        if(st == -1) return vector<int>{-1, -1};
        return vector<int>{st, ed};
    }
    
    int binarySearch(const vector<int>&nums, int target, int left, int right, bool tag){

        int mid = -1, rtn = -1;
        
        while(left <= right){
            mid = left + right >> 1;
            if(nums[mid] > target) right = mid - 1;
            else if(nums[mid] < target) left = mid + 1;
            else break;
        }
        if(left > right) return -1;
        
        if(tag) rtn = binarySearch(nums, left, mid-1, tag);
        else rtn = binarySearch(nums, mid+1, right, tag);
        // ensure to find target in this self-recursion
        if(rtn == -1) return mid;
        return rtn;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int leftMost = binarySearch(nums, target, 0, nums.size()-1, true);
        if(leftMost == -1) return vector<int>{-1, -1};
        int rightMost = binarySearch(nums, target, leftMost, nums.size()-1, false);
        return vector<int>{leftMost, rightMost};
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<int> ret = Solution().searchRange(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}