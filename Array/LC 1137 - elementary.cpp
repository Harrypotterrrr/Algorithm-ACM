/*
1137. N-th Tribonacci Number
*/

class Solution {
public:
    int tribonacci(int n) {
        int ppre = 0, pre = 1, cur = 1;
        int tmp;
        for(int i=2 ; i<n ; i++){
            tmp = cur;
            cur += ppre + pre;
            ppre = pre;
            pre = tmp;
        }
        if(n == 0) return 0;
        return cur;
    }
};