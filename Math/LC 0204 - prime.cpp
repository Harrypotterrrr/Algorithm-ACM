/*
204. Count Primes
*/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool>vec(n, true);
        int ctr = 0;
        for(int i=2; i<n ; i++){
            if(!vec[i]) continue;
            ctr++;
            for(long j=2*i ; j<n; j+=i) vec[j] = false;
        }
        return ctr;
    }
};