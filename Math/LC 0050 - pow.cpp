/*
50. Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000

Example 2:

Input: 2.10000, 3
Output: 9.26100

Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
*/

#include "../include/include.h"

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long num = n;
        double mul = x;
        if(num < 0){
            mul = 1.0 / mul;
            num = - num;     
        }
        while(num){
            if(num & 0x01) ans *= mul;
            mul *= mul;
            num >>= 1;
        }
        return ans;
    }
};

int main()
{

}