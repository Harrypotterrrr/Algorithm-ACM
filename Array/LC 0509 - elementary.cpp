/*
509. Fibonacci Number
*/

class Solution {
public:
    int fib(int n) {
        int pre = 0, cur = 1, tmp;
        for(int i=1 ; i<n ; i++){
            tmp = cur;
            cur += pre;
            pre = tmp;
        }
        if(!n) return 0;
        return cur;
    }
};