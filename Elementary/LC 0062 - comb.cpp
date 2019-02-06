/*
62. Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Example 2:

Input: m = 7, n = 3
Output: 28
*/

#include "../include/include.h"

class Solution {
public:
    
    int calcComb(int m, int n){
        int k = min(m - n , n);
        long long rtn=1;
        for(int i=1 ; i<=k ; i++)
            rtn = rtn * (m-i+1) / i;
        return rtn;
    }
    
    # DP solution
    int uniquePaths_DP(int m, int n) {
        int ctr[m];
        for(int i=0 ; i<m ; i++)
            ctr[i] = 1;
        for(int i=1 ; i<n ; i++){
            for(int j=1 ; j<m ; j++)
                ctr[j] += ctr[j-1];
        }
        return ctr[m-1];
    }
    
    # Combinatorial solution
    int uniquePaths(int m, int n) {
        
        return calcComb(m + n - 2, n - 1);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}