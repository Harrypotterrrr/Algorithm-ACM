/*
31. Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 â†’ 1,3,2
3,2,1 â†’ 1,2,3
1,1,5 â†’ 1,5,1
*/

#include "../include/include.h"

class Solution {
public:

	void nextPermutation(vector<int>& nums) {
		if (nums.size() == 1)
			return;

		int i = nums.size() - 1, j = nums.size() - 1;
		while (i > 0 && nums[i - 1] >= nums[i]) i--;
		if (i > 0) {
			while (j >= i && nums[j] <= nums[i - 1]) j--;
			swap(nums[j], nums[i - 1]);
		}
		reverse(nums.begin() + i, nums.end());
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

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}

	if (length == 0) {
		return "[]";
	}

	string result;
	for (int index = 0; index < length; index++) {
		int number = list[index];
		result += to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);

		Solution().nextPermutation(nums);

		string out = integerVectorToString(nums);
		cout << out << endl;
	}
	return 0;
}