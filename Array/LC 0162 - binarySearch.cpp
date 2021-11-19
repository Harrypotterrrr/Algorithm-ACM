/************************************************
Problem: 		162. Find Peak Element
Algorithm: 		Binary Search
Difficulty: 	**
Importance:		***
Remark:			
*************************************************/

// Solution 1: linear search O(N)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for(int i=0 ; i<n-1 ; i++)
            if(nums[i] > nums[i+1])
                return i;
        return n-1;
    }
};

// Solution 2: binary search iterative way O(log(N))

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        while(left < right){
            int mid = ((right - left) >> 1) + left;
            if(nums[mid] > nums[mid+1]) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

// Solution 3: binary search recursive way O(log(N))

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        function<int(int, int)> find_peak = [&](int left, int right){
            if(left == right) return left;
            int mid = ((right - left) >> 1) + left;
            if(nums[mid] > nums[mid+1]) return find_peak(left, mid);
            else return find_peak(mid+1, right);
        };
        return find_peak(0, n-1);
    }
    
};
