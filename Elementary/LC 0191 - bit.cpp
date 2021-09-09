/*
191. Number of 1 Bits
*/


// Solution 1: iteration

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ctr = 0;
        while(n){
            if(n & 1) ctr++;
            n = n >> 1;
        }
        return ctr;
    }
};

// Solution 2:

class Solution {
public:
    int hammingWeight(uint32_t n) {
          int ctr = 0;
        while(n){
            n &= (n-1);
            ctr++;
        }
        return ctr;
    }
};

// Solution 3:  Hamming weight 
// reference: https://www.cnblogs.com/jawiezhu/p/4395063.html

class Solution {
public:
    int hammingWeight(uint32_t n) {
          n = (n&0x55555555) + ((n>>1)&0x55555555);
          n = (n&0x33333333) + ((n>>2)&0x33333333);
          n = (n&0x0f0f0f0f) + ((n>>4)&0x0f0f0f0f);
          n = (n&0x00ff00ff) + ((n>>8)&0x00ff00ff);
          n = (n&0x0000ffff) + ((n>>16)&0x0000ffff);
          return n;
    }
};