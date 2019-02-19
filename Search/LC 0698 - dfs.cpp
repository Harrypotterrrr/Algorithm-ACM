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

	static bool cmd(int a, int b) {
		return a > b;
	}

	bool dfs(int ctr, int sum, int st) {
		if (sum == target) {
			if (ctr + 1 == n) return true;
			return dfs(ctr + 1, 0, 0);
		}
		for (int i = st; i < V.size(); i++) {
			if (flag[i] == false) continue;
			if (sum + V[i] > target) continue;
			flag[i] = false;
			if (dfs(ctr, sum + V[i], i + 1) == true) return true;
			flag[i] = true;
			while (i < V.size() - 1 && V[i] == V[i + 1]) i++; 
		}
		return false;
	}

	bool canPartitionKSubsets(vector<int>& nums, int k) {
		for (auto i = 0; i<nums.size(); i++) {
			if (nums[i] == 0) {
				k--;
				continue;
			}
			V.push_back(nums[i]);
			flag.push_back(true);
			Sum += nums[i];
		}
		if (Sum % k != 0) return false;
		sort(V.begin(), V.end(), Solution::cmd);
		n = k;
		target = Sum / n;
		return dfs(0, 0, 0);
	}
}; 
