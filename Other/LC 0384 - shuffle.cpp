/************************************************
Problem: 		384. Shuffle an Array
Algorithm: 		Array
Difficulty: 	**
Importance:		***
Remark:			shuffle
*************************************************/

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

// Solution 1: STL list O(n^2), space O(N)

class Solution {
public:
    
    vector<int> vec;
    Solution(vector<int>& nums) {
        vec = nums;
    }
    
    vector<int> reset() {
        return vec;
    }
    
    vector<int> shuffle() {
        list<int>ll(vec.begin(), vec.end());
        vector<int>rtn;
        for(int i=0 ; i<vec.size() ; i++){
            auto it = ll.begin();
            int id = rand() % ll.size();
            advance(it, id);
            rtn.push_back(*it);
            ll.erase(it);
        }
        return rtn;
    }
};

// Solution 2: O(n), space O(n)

class Solution {
public:
    
    vector<int> vec;
    Solution(vector<int>& nums) {
        vec = nums;
    }
    
    vector<int> reset() {
        return vec;
    }
    
    vector<int> shuffle() {
        vector<int>rtn;
        vector<int>tmp(vec.begin(), vec.end());
        int n = vec.size();
        for(int i=n ; i>0 ; i--){
            int id = rand() % i;
            rtn.push_back(tmp[id]);
            tmp[id] = tmp.back();
            tmp.pop_back();
        }
        return rtn;
    }
};

// Solution 3: O(n), space O(1)

class Solution {
public:
    
    vector<int> vec;
    Solution(vector<int>& nums) {
        vec = nums;
    }
    
    vector<int> reset() {
        return vec;
    }
    
    vector<int> shuffle() {
        vector<int>rtn(vec.begin(), vec.end());
        int n = vec.size();
        for(int i=0 ; i<n ; i++){
            int id = rand() % n;
            swap(rtn[id], rtn[i]);
        }
        return rtn;
    }
};
