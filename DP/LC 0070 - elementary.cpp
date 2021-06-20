/*
70. Climbing Stairs
*/

// Solution 1

class Solution {
public:

    int climbStairs(int n) {
        if(n == 1)
            return 1;
        vector<int>store(n+1, 0);
        store[1] = 1;
        store[2] = 2;
        for(int i=3; i <=n ; i++)
            store[i] = store[i-1] + store[i-2];
        return store[n];
    }
};

// Solution 2

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1, tmp;
        for(int i=2 ; i<=n ; i++){
            tmp = b;
            b += a;
            a = tmp;
        }
        return b;
    }
};