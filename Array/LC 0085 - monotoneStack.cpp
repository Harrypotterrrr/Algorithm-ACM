/*
85. Maximal Rectangle
*/

// Solution 1: TLE O(n^2)

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int n=matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<int>vec(m, 0);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j] == '0')
                    vec[j] = 0;
                else
                    vec[j] ++;
            }
            int rtn = largestRectangleArea(vec);
            ans = ans > rtn ? ans : rtn;
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size(), ans = 0, tmp;
        stack<int> S; // Store the index of each bar
        
        for(int i=0 ; i<n ; i++){
            while(!S.empty() && heights[S.top()] >= heights[i]){
                int cur = S.top(); S.pop();
                tmp = heights[cur] * (S.empty() ? i : (i - S.top() - 1));
                ans = ans > tmp ? ans : tmp; 
            }
            S.push(i);
        }
        
        return ans;
    }
};

// Solution 2: TODO