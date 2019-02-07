/*
4. Median of Two Sorted Arrays

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

#include "../include/include.h"

class Solution {
public:

	double findKth(const vector<int>&V1, const vector<int>&V2, int offset1, int offset2, int len1, int len2, int k) {

		int p, q;
		if (len1 > len2) {
			q = min(k / 2, len2);
			p = k - q;
		}
		else {
			p = min(k / 2, len1);
			q = k - p;
		}
		if (offset1 >= V1.size())
			return V2[offset2 + k - 1];
		if (offset2 >= V2.size())
			return V1[offset1 + k - 1];
		if (k == 1)
			return min(V1[offset1], V2[offset2]);


		int comp1 = V1[offset1 + p - 1];
		int comp2 = V2[offset2 + q - 1];

		if (comp1 == comp2)
			return comp1;
		else if (comp1 > comp2) {
			return findKth(V1, V2, offset1, offset2 + q, len1, len2 - q, k - q);
		}
		else {
			return findKth(V1, V2, offset1 + p, offset2, len1 - p, len2, k - p);
		}
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { 
		int k = nums1.size() + nums2.size();
		if (k & 0x01)
			return findKth(nums1, nums2, 0, 0, nums1.size(), nums2.size(), (k >> 1) + 1);
		else {
			return (findKth(nums1, nums2, 0, 0, nums1.size(), nums2.size(), (k >> 1)) + findKth(nums1, nums2, 0, 0, nums1.size(), nums2.size(), (k >> 1) + 1)) / 2.0;
		}

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
		vector<int> nums1 = stringToIntegerVector(line);
		getline(cin, line);
		vector<int> nums2 = stringToIntegerVector(line);

		double ret = Solution().findMedianSortedArrays(nums1, nums2);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}