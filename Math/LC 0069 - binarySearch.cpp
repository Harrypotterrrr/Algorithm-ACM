/*
69. Sqrt(x)
*/

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        while(left <= right){
            
            long long mid = (left + right) >> 1;
            long long mul = mid * mid;
            
            if(mul == x)
                return mid;
            
            if(mul > x) {
                if((mid-1) * (mid-1) <= x)
                    return mid - 1;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        
        return -1;
    }
};

// Solution 2
class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1)
            return x;

        int left = 0, right = x;
        int ans;
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            if (x / mid == mid) 
                return mid;
            else if(x / mid > mid){
                left = mid + 1;
                ans = mid;
            }
            else
                right = mid - 1;
        }
        return ans;
    }
};
