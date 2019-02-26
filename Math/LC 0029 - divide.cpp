/*
29. Divide Two Integers

Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3

Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/

#include "../include/include.h"

class Solution {
public:
    int divide_slow(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        bool flag = (dividend > 0) ^ (divisor > 0);
        long dd = labs(dividend), dr = labs(divisor);
        
        if(!dd || dd < dr) return 0;

        long dr_t = dr, ans = 0, ctr = 0;
        while(dr_t < dd){
            dr_t <<= 1;
            ctr ++;
        }
        
        while(dd >= dr){
            while(dd < dr_t){
                dr_t >>= 1;
                ctr --;
            }
            dd -= dr_t;
            ans += 1 << ctr;
        }
        return flag ? -ans : ans;
    }

    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        long dd = labs(dividend), dr = labs(divisor), ans = 0;
        bool flag = (dividend > 0) ^ (divisor > 0);
        
        while(dd >= dr){
            long ctr = 1, tmp = dr;
            while(dd >= tmp << 1){
                tmp <<= 1;
                ctr <<= 1;
            }
            dd -= tmp;
            ans += ctr;
        }
        return flag ? -ans : ans;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int dividend = stringToInteger(line);
        getline(cin, line);
        int divisor = stringToInteger(line);
        
        int ret = Solution().divide(dividend, divisor);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}