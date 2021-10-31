/************************************************
Problem: 		1762. Buildings With an Ocean View
Algorithm: 		Array, Monotone Stack
Difficulty: 	*
Importance:		***
Remark:			
*************************************************/


// Solution 1: linear traversal

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int>ans({n-1});
        int maxn = heights.back();
        for(int i=n-2 ; i>=0 ; i--){
            if(heights[i] > maxn){
                ans.push_back(i);
                maxn = heights[i];
            }
        }
        for(int i=0 ; i<(ans.size()>>1) ; i++)
            swap(ans[i], ans[ans.size()-i-1]);
        return ans;
    }
};

// Solution 2: stack traverse from left to right

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int>ans;
        for(int i=0 ; i<n ; i++){
            while(!ans.empty() && heights[ans.back()] <= heights[i])
                ans.pop_back();
            ans.push_back(i);
        }
        return ans;
    }
};

// Solution 3: monotone stack from right to left

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int>ans;
        stack<int>S;
        for(int i=n-1 ; i>=0 ; i--){
            while(!S.empty() && heights[i] > heights[S.top()])
                S.pop();
            if(S.empty()) ans.push_back(i);
            S.push(i);
        }
        for(int i=0 ; i<(ans.size()>>1) ; i++)
            swap(ans[i], ans[ans.size()-1-i]);
        return ans;
    }
};