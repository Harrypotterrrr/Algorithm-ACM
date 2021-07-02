/*
278. First Bad Version
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return solve(1, n);
    }
    
    int solve(int left, int right){
        if(left == right)
            return left;
        int mid = left + ((right - left) >> 1);
        if(isBadVersion(mid))
            return solve(left, mid);
        else
            return solve(mid+1, right);
    }
};


// Solution 2: iteration

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left != right){
            int mid = left + ((right - left) >> 1);
            if(isBadVersion(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};