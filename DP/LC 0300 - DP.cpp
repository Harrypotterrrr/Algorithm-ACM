/*
300. Longest Increasing Subsequence
*/


// Solution 1: dp, time: O(n^2)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(), 1);
        int ans = 1;
        for(int i=1 ; i<nums.size() ; i++){
            for(int j=0 ; j<i ; j++){
                if(nums[i] > nums[j]){
                    dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
                }
            }
            ans = ans > dp[i] ? ans : dp[i];
        }
        return ans;
    }
};

// Solution 2:  binary search, time: O(nlong(n))

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		vector<int>vec = { nums[0] };
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] < vec[0]) vec[0] = nums[i];
			else if (nums[i] > vec.back()) vec.push_back(nums[i]);
			else {
				int left = 0, right = vec.size() - 1;
				while (left < right) {
					int mid = ((right - left) >> 1) + left;
					if (vec[mid] > nums[i]) right = mid;
					else if (vec[mid] < nums[i]) left = mid + 1;
					else {
						left = mid;
						break;
					}
				}
				vec[left] = nums[i];
			}
		}
		return vec.size();
    }
};

// Solution 3: a little bit different

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		vector<int>vec = { nums[0] };
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] < vec[0]) vec[0] = nums[i];
			else if (nums[i] > vec.back()) vec.push_back(nums[i]);
			else {
				int left = 0, right = vec.size() - 1;
				while (left < right) {
					int mid = ((right - left) >> 1) + left;
					if (vec[mid] < nums[i]) left = mid + 1;
					else right = mid;
				}
				vec[right] = nums[i];
			}
		}
		return vec.size();
    }
};

// Solution 4: a bit more intuitively way

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		vector<int>vec = { nums[0] };
		for (int i = 0; i < nums.size(); i++) {
			int left = 0, right = vec.size() - 1;
			while (left < right) {
				int mid = ((right - left) >> 1) + left;
				if (vec[mid] < nums[i]) left = mid + 1;
				else right = mid;
			}
			if (vec[right] < nums[i])
				vec.push_back(nums[i]);
			else
				vec[right] = nums[i];
		}
		return vec.size();
    }
};

// Solution 5: lower_bound inner function

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		vector<int>vec = { nums[0] };
		for (int i = 0; i < nums.size(); i++) {
            auto it = lower_bound(vec.begin(), vec.end(), nums[i]);
            if(it == vec.end())
				vec.push_back(nums[i]);
			else
				*it = nums[i];
		}
		return vec.size();
    }
};

// Solution 6: upper_bound inner function

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		vector<int>vec = { nums[0] };
		for (int i = 0; i < nums.size(); i++) {
            if(find(vec.begin(), vec.end(), nums[i]) != vec.end()) continue;
            auto it = upper_bound(vec.begin(), vec.end(), nums[i]);
            if(it == vec.end())
				vec.push_back(nums[i]);
			else
				*it = nums[i];
		}
		return vec.size();
    }
};