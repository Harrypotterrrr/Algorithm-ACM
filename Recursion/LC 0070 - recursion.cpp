/*
70. Climbing Stairs
*/

class Solution {
public:
    int recursion(vector<int>&store, int n) {
        if (n <= 2){
            store[n] = n;
            return store[n];
        }
        if(!store[n])
            store[n] = recursion(store, n-1) + recursion(store, n-2);
        return store[n];
    }
    int climbStairs(int n) {
        vector<int>store(n+1, 0);
        recursion(store, n);
        return store[n];
    }
};
