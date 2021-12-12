/************************************************
Problem: 		1306. Jump Game III
Algorithm: 		DFS, BFS
Difficulty: 	*
Importance:		**
Remark:			
*************************************************/

// Solution 1: DFS

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool>memo(n, false);
        function<bool(int)> solve = [&n, &solve, &memo, &arr](int k){
            if(k < 0 || k >= n) return false;
            if(arr[k] == 0) return true;
            if(memo[k]) return false;
            memo[k] = true;
            return solve(k+arr[k]) || solve(k-arr[k]);
        };
        return solve(start);
    }
};


// Solution 2: BFS

class Solution {
public:
      
    bool canReach(vector<int>& arr, int start) {
        vector<bool> flag (arr.size(), false);
        queue<int>Q;
        Q.push(start);
        flag[start] = true;
        while(!Q.empty()){
            int cur = Q.front();
            Q.pop();
            if(arr[cur] == 0)
                return true;
            
            if(cur + arr[cur] < arr.size() && !flag[cur+arr[cur]]){
                if(arr[cur+arr[cur]] == 0)
                    return true;
                flag[cur+arr[cur]] = true;
                Q.push(cur+arr[cur]);
            }
            if(cur - arr[cur] >= 0 && !flag[cur-arr[cur]]){
                if(arr[cur-arr[cur]] == 0)
                    return true;
                flag[cur-arr[cur]] = true;
                Q.push(cur-arr[cur]);
            }
            
        }
        return false;
    }
};