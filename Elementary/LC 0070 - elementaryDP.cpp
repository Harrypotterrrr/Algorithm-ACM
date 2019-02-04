/*
70. Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

*/

#include "../include/include.h"

class Solution {
public:
    int climbStairs(int n) {
        int pre = 2;
        int ppre = 1;
        int cur;
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        for(auto i=3;i<=n;i++){
            cur = pre + ppre;
            ppre = pre;
            pre = cur;
        }
        
        return cur;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}