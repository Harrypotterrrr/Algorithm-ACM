/************************************************
Problem: 		128. Longest Consecutive Sequence
Algorithm: 		Array, STL, Union Find
Difficulty: 	***
Importance:		**
Remark:			IQ, union-find
*************************************************/

// Solution 1: O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>uS;
        for(auto &i: nums) uS.insert(i);
        int ans = 0, cur;
        for(auto i: uS){
            if(!uS.count(i-1)){
                cur = 1;
                while(uS.count(++i)) cur ++;
                ans = ans > cur ? ans : cur;
            }
        }
        return ans;
    }
};

// Solution 2: O(n)
// reference: https://leetcode.com/problems/longest-consecutive-sequence/discuss/41088/Possibly-shortest-cpp-solution-only-6-lines

// TODO

// Solution 3: Union-find

class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        vector<int>uf(n);
        for(int i=0 ; i<n ; i++) uf[i] = i; // disjoint
        
        function<int(int)> find = [&uf](int i){
            while(i != uf[i]){
                uf[i] = uf[uf[i]];
                i = uf[i];
            }
            return i;
        };
        function<void(int, int)> unite = [&uf, &find](int i, int j){
            i = find(i);
            j = find(j);
            uf[i] = j;
        };
        
        unordered_map<int, int>uM;
        for(int i=0 ; i<n ; i++){
            auto num = nums[i];
            if(uM.find(num) != uM.end()) continue;
            uM[num] = i;
            if(uM.find(num+1) != uM.end())
                unite(i, uM[num+1]);
            if(uM.find(num-1) != uM.end())
                unite(i, uM[num-1]);
        }
        
        int ans = 0;
        vector<int> ctr(n, 0);
        for(int i=0 ; i<n ; i++) 
            ans = max(ans, ++ctr[find(i)]);
            
        return ans;
    }
};