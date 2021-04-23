/*
96. Unique Binary Search Trees
*/

// `C(n)=Ci(2n,n)/n+1`
class Solution {
public:
    
    long long calBinomialCoeff(int n) {
        long long tmp = 1;
        for(int i=1 ; i<=n ; i++){
            tmp *= 2 * n - i + 1;
            tmp /= i;
        }
        return tmp;
    }
    
    int numTrees(int n) {
        return calBinomialCoeff(n) / (n + 1);
    }
};