/*
84. Largest Rectangle in Histogram
*/

// Solution 1: TLE O(n^2)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0, n = heights.size();
        for(int i=0 ; i<n ; i++){
            if(i+1 < n && heights[i] <= heights[i+1]) continue;
            int minn = heights[i];
            for(int j=i ; j>=0 ; j--){
                minn = minn < heights[j] ? minn : heights[j];
                int cur = minn * (i-j+1);
                ans = ans > cur ? ans : cur;
            }
        }
        return ans;
    }
};

// Solution 2: O(n^2)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        for(int i=0 ; i<heights.size() ; i++){
            if(i > 0 && heights[i] == heights[i-1])
                continue;
            int ctr = 1;
            for(int j=1 ; j+i < heights.size() && heights[j+i] >= heights[i] ; j++)
				ctr++;
            for(int j=1 ; i-j >= 0 && heights[i-j] >= heights[i]; j++)
				ctr++;
            ans = ans > ctr * heights[i] ? ans : ctr * heights[i];
        }
        return ans;
    }
};

// Solution 3: stack O(n), using stack to record the nearest smaller value of the current one

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0, tmp;
        stack<pair<int, int>> S;
        vector<int>vec(n, 0);
        for(int i=0 ; i<n ; i++){
            while(!S.empty() && S.top().first >= heights[i])
                S.pop();
            if(S.empty()) vec[i] = -1;
            else vec[i] = S.top().second;
            S.push(pair<int, int>({heights[i], i}));
        }
        while(!S.empty()) S.pop();
        for(int i=n-1 ; i>=0 ; i--){
            while(!S.empty() && S.top().first >= heights[i])
                S.pop();
            if(S.empty()) tmp = heights[i] * (n - vec[i] - 1);
            else tmp = heights[i] * (S.top().second - vec[i] - 1);
            ans = ans > tmp ? ans : tmp;
            S.push(pair<int, int>({heights[i], i}));
        }
        return ans;
    }
};

// Solution 4: monotone Stack, only one traversal optimization

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0, tmp;
        stack<int> S; // Store the index of each bar
        vector<int>vec(n, 0);
        
        for(int i=0 ; i<n ; i++){
            while(!S.empty() && heights[S.top()] >= heights[i]){
                tmp = (i - vec[S.top()] - 1) * heights[S.top()];
                ans = ans > tmp ? ans : tmp; 
                S.pop();
            }
            if(S.empty()) vec[i] = -1;
            else vec[i] = S.top();
            S.push(i);
        }
        
        while(!S.empty()){
            tmp = (n - vec[S.top()] - 1) * heights[S.top()];
            ans = ans > tmp ? ans : tmp;
            S.pop();
        }

        return ans;
    }
};

// Solution 5: further improvement

class Solution {
public:
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