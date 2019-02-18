/*
698. Partition to K Equal Sum Subsets

Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
 

Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.
*/

#include "../include/include.h"

class Solution {
public:

	int Sum, target, n;
	vector<int>V;
	vector<bool>flag;
	bool dfs(int ctr, int sum, int st) {
		if (sum == target) {
			if (ctr + 1 == n) return true;
			//if(dfs(ctr + 1, 0, 0) == true) return true;
			return dfs(ctr + 1, 0, 0);
		}
		for (int i = st; i<V.size(); i++) {
			if (flag[i] == false) continue;
			//if (sum + V[i] > target) break;
			flag[i] = false;
			if (dfs(ctr, sum + V[i], i + 1) == true) return true;
			flag[i] = true;
		}
		return false;
	}

	bool canPartitionKSubsets(vector<int>& nums, int k) {
		for (auto i = 0; i<nums.size(); i++) {
			V.push_back(nums[i]);
			flag.push_back(true);
			Sum += nums[i];
		}
		if (Sum % k != 0) return false;
		//std::sort(V.begin(), V.end());
		n = k;
		target = Sum / n;
		return dfs(0, 0, 0);
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

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);
		getline(cin, line);
		int k = stringToInteger(line);

		bool ret = Solution().canPartitionKSubsets(nums, k);

		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}