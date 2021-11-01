/************************************************
Problem: 		1424. Diagonal Traverse II
Algorithm: 		Array, Iteration
Difficulty: 	***
Importance:		***
Remark:			Diagnally iterate the matrix
*************************************************/

// Solution 1: TLE

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size(), m = 1;
        for(int i=0 ; i<nums.size() ; i++)
            m = m > nums[i].size() ? m : nums[i].size();
        
        vector<vector<int>>vec(n+m-1);
        vector<int>ans;
        
        for(int j=0 ; j<m ; j++){
            for(int i=0 ; i<n ; i++){
                if(j >= nums[i].size()) continue;
                vec[i+j].push_back(nums[i][j]);
            }
        }
        for(int i=0 ; i<m+n-1 ; i++){
            for(auto &j: vec[i])
                ans.push_back(j);
        }
        return ans;
    }
};

// Solution 2: use STL list O(N), where N is the total number of elements in nums

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size(), m = 1;
        
        list<pair<pair<int, int>, int>>ll;
        for(int i=0 ; i<nums.size() ; i++){
            ll.push_back({{i, 0}, nums[i].size()});
            m = m > nums[i].size() ? m : nums[i].size();
        }
        
        vector<vector<int>>vec(n+m-1);
        vector<int>ans;
        
        while(ll.size()){
            for(auto it = ll.begin() ; it != ll.end() ; ){
                int &x = it->first.first;
                int &y = it->first.second;
                int &len = it->second;
                vec[x+y].push_back(nums[x][y]);
                if(++y >= len){
                    auto tmp = it;
                    it++;
                    ll.erase(tmp);
                }
                else it++;
            }
        }
       
        for(int i=0 ; i<m+n-1 ; i++){
            for(auto &j: vec[i])
                ans.push_back(j);
        }
        return ans;
    }
};

// Solution 3: use STL unordered_map, time complexity same with solution 2

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size(), maxn = 0;
        unordered_map<int, vector<int>>uM;
        vector<int>ans;

        for(int i=0 ; i<n ; i++){
            for(int j=0; j<nums[i].size() ; j++){
                uM[i+j].push_back(nums[i][j]);
                maxn = maxn > i+j ? maxn : i+j;
            }
        }
        
        for(int i=0 ; i<=maxn ; i++){
            for(auto j=uM[i].rbegin() ; j!=uM[i].rend() ; j++)
                ans.push_back(*j);
        }
        return ans;
    }
};