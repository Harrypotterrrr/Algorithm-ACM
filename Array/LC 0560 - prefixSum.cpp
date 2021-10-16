/*
560. Subarray Sum Equals K
Array, Hashtable, PrefixSum
*/


// Solution 1: brute force, TLE, O(n^2)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>vec({0});
        int ctr = 0;
        for(auto &i: nums){
            vec.push_back(vec.back() + i);
            for(int j=0 ; j<vec.size()-1 ; j++){
                if(vec.back() - vec[j] == k)
                    ctr++;
            }
        }
        return ctr;
    }
};

// Solution 2: use map O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>uM({{0, 1}});
        int prefix = 0, ctr = 0;
        for(auto &i: nums){
            prefix += i;
            ctr += uM[prefix - k];
            uM[prefix] ++;
        }
        return ctr;
    }
};