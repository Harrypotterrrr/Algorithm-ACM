/*
118. Pascal's Triangle
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans = {{1}};
        for(int i=1; i<numRows ; i++){
            vector<int>cur = {1};
            for(int j=1 ; j<i ; j++){
                cur.push_back(ans.back()[j-1] + ans.back()[j]);
            }
            cur.push_back(1);
            ans.push_back(cur);
        }
        return ans;
    }
};


// Solution 2: initialize and resize

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        for(int i=0; i<numRows ; i++){
            ans[i].resize(i+1, 1);
            for(int j=1 ; j<i ; j++)
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
        return ans;
    }
};