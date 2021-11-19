/************************************************
Problem: 		162. Find Peak Element
Algorithm: 		Bit Manipulation
Difficulty: 	*
Importance:		*
Remark:			Brian Kernighan's Algorithm
*************************************************/


// Solution 1: bit shift

class Solution {
public:
    int hammingDistance(int x, int y) {
        unsigned int z = x ^ y;
        int ans = 0;
        while(z){
            ans += z & 1;
            z >>= 1;
        }
        return ans;
    }
};

// Solution 2: builtin bit count

class Solution {
public:
    int hammingDistance(int x, int y) {
        unsigned int z = x ^ y;
        return __builtin_popcount(z);
    }
};

// Solution 3: builtin bit count

class Solution {
public:
    int hammingDistance(int x, int y) {
        unsigned int z = x ^ y;
        bitset<32>bits(z);
        return bits.count();
    }
};

// Solution 4: Brian Kernighan's Algorithm

class Solution {
public:
    int hammingDistance(int x, int y) {
        unsigned int z = x ^ y;
        int ans = 0;
        while(z){
            z &= z-1;
            ans++;
        }
        return ans;
    }
};
