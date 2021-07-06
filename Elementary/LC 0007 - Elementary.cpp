/*
7. Reverse Integer

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321

Example 2:

Input: -123
Output: -321

Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [âˆ’231,  231 âˆ’ 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

#include "../include/include.h"

class Solution {
public:
    int reverse(int x) {
        int cur;
        long long num = 0;
        while(x){
            cur = x % 10;
            x /= 10;
            num *= 10;
            num += cur;
        }
        if (num > INT_MAX || num < INT_MIN)
            return 0;
        return num;
    }
};

// Solution 2: not use long type

class Solution {
public:
    int reverse(int x) {
        int n = x, ans = 0;
        while(n){
            if(x > 0){
                if(ans > INT_MAX / 10)
                    return 0;
                ans *= 10;
                if(ans > INT_MAX - n % 10)
                    return 0;
            }
            else{
                if(ans < INT_MIN / 10)
                    return 0;
                ans *= 10;
                if(ans < INT_MIN - n % 10)
                    return 0;
            }
            ans += (n % 10);
            n /= 10;
        }
        return ans;
    }
};


int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}