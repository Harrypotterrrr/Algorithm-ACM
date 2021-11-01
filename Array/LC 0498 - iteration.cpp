/************************************************
Problem: 		498. Diagonal Traverse
Algorithm: 		Array, Iteration
Difficulty: 	**
Importance:		****
Remark:			Diagnally iterate the matrix
*************************************************/

// Solution 1: diagonally traversal, time O((m+n)^2) space O(mn)

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans;
        for(int i=0 ; i<n+m-1 ; i++){
            for(int j=0 ; j<=i ; j++){
                int x = j;
                int y = i-j;
                if(!(i % 2)) swap(x, y);
                if(x >= n || y >= m) continue;
                ans.push_back(mat[x][y]);
            }
        }
        return ans;
    }
};

// Solution 2: use additional vector to optimize time, time O(mn) space O(2mn)

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>>vec(n+m-1);
        vector<int>ans;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++)
                vec[i+j].push_back(mat[i][j]);
        }
        for(int i=0 ; i<m+n-1 ; i++)
            if(i % 2 == 0)
                reverse(vec[i].begin(), vec[i].end());
        for(int i=0 ; i<m+n-1 ; i++){
            for(auto &j: vec[i])
                ans.push_back(j);
        }
        return ans;
    }
};

// Solution 3: use STL unordered_map, time O(mn) space O(mn)

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), maxn = 0;
        unordered_map<int, vector<int>>uM;
        vector<int>ans;

        for(int i=0 ; i<n ; i++){
            for(int j=0; j<mat[i].size() ; j++){
                uM[i+j].push_back(mat[i][j]);
                maxn = maxn > i+j ? maxn : i+j;
            }
        }
        
        for(int i=0 ; i<=maxn ; i++){
            if(i % 2 == 0){
                for(auto j=uM[i].rbegin() ; j!=uM[i].rend() ; j++)
                    ans.push_back(*j);
            }
            else{
                 for(auto j=uM[i].begin() ; j!=uM[i].end() ; j++)
                    ans.push_back(*j);               
            }
        }
        return ans;
    }
};