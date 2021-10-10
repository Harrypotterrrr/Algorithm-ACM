/*
201. Bitwise AND of Numbers Range
*/


// Solution 1:

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for(int i=30 ; i>=0 ; i--){
            if((right >> i) & 1){
                if((left >> i) & 1)
                    ans += (1 << i);
                else
                    break;
            }
        }
        return ans;
    }
};

// Solution 2: INT_MAX as mask

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        unsigned int mask = INT_MAX;
        while((left & mask) != (right & mask)){
            mask <<= 1;
        }
        return right & mask;
    }
};

// Solution 3: count

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ctr = 0;
        
        while(left != right){
            right >>= 1;
            left >>= 1;
            ctr ++;
        }
        return right << ctr;
    }
};

// Solution 4: recursion

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        return (right > left) ? (rangeBitwiseAnd(left >> 1, right >> 1) << 1) : right;
    }
};

// Solution 5: Brian Kernighan's Algorithm

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(right > left)
			// Remove the last 1 bit from the left of right value
            right = right & (right - 1);
        return right;
    }
};