/*
31. Next Permutation

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

#include "../include/include.h"

class Solution {
public:
	int search_tedious(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;

		int left = 0, right = nums.size() - 1, mid;
		while (true) {
			if (nums[left] <= nums[right]) {
				while (left <= right) {
					mid = left + right >> 1;
					if (nums[mid] == target) return mid;
					else if (nums[mid] > target) right = mid - 1;
					else left = mid + 1;
				}
				if (left > right) return -1;
				return left;

			}
			else {
				mid = left + right >> 1;
				if (nums[mid] >= nums[left]) {
					if (target >= nums[left] && target <= nums[mid]) right = mid;
					else left = mid + 1;
				}
				else {
					if (target >= nums[mid] && target <= nums[right]) left = mid;
					else right = mid - 1;
				}
			}
		}
		return -1;
	}

	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;

		int left = 0, right = nums.size() - 1, mid;
		while (left <= right) {
			mid = left + right >> 1;
			if (target == nums[mid]) return mid;
			if (nums[mid] >= nums[left]) {
				if (target >= nums[left] && target <= nums[mid]) right = mid;
				else left = mid + 1;
			}
			else {
				if (target >= nums[mid] && target <= nums[right]) left = mid;
				else right = mid - 1;
			}
		}
		return -1;
	}

	// clever solutions
	int search_addInf(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;

		int left = 0, right = nums.size() - 1, mid, comp;


		while (left <= right) {
			mid = left + right >> 1;
			if (target == nums[mid]) return mid;
			if (target == nums[0]) return 0;
			comp = (target > nums[0]) == (nums[mid] >= nums[0])
				? nums[mid] : target > nums[0] ? INT_MAX : INT_MIN;
			if (comp == target) return mid;
			else if (comp > target) right = mid - 1;
			else left = mid + 1;
		}
		return -1;
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

		int ret = Solution().search(nums, target);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}