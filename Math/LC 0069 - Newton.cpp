/*
69. Sqrt(x)
*/

// xi+1=xi - (xi2 - n) / (2xi) = xi - xi / 2 + n / (2xi) = xi / 2 + n / 2xi = (xi + n/xi) / 2
class Solution {
public:
    int mySqrt(int x) {
        double last = -1, cur = 1;
        while(abs(last - cur) > 1e-5){
            last = cur;
            cur = (cur + x / cur) / 2;
        }
        return int(cur);
    }
};

// Solution 2
class Solution {
public:
    int mySqrt(int x) {
        long ans = x;
        while(ans * ans > x){
            ans = (ans + x / ans) / 2;
        }
        return int(ans);
    }
};