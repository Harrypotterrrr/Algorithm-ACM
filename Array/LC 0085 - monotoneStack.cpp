/*
85. Maximal Rectangle
*/

// Solution 1: O(mn) using monotone stack

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

// Solution 2: scan line by line using time of O(mn)

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<int> h(m, 0), l(m, 0), r(m, m-1);
        for(int i=0 ; i<n ; i++){
            int left_k = 0, right_k = m-1;
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j] == '1'){
                    h[j]++;
                    l[j] = l[j] > left_k ? l[j] : left_k;
                }
                else{
                    h[j] = 0;
                    l[j] = 0;
                    left_k = j+1;
                }
            }
            for(int j=m-1 ; j>=0 ; j--){
                if(matrix[i][j] == '1'){
                    r[j] = r[j] < right_k ? r[j] : right_k;
                    ans = ans > h[j] * (r[j] - l[j] + 1) ? ans : h[j] * (r[j] - l[j] + 1);
                }
                else{
                    r[j] = m-1;
                    right_k = j-1;
                }
            }
        }
        return ans;
    }
};

// Solution 3: calculate adjacent elemetns O(mn^2)

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<vector<int>>vec(n, vector<int>(m, 0));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j] == '0') continue;
                if(j > 0) vec[i][j] = vec[i][j-1] + 1;
                else vec[i][j] = 1;
            }
        }
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j] == '0') continue;
                int width = vec[i][j];
                for(int k=i ; k>=0 && vec[k][j] > 0 ; k--){
                    width = width < vec[k][j] ? width : vec[k][j];
                    ans = ans > width * (i - k + 1) ? ans : width * (i - k + 1);
                }
            }
        }
        return ans;
    }
};