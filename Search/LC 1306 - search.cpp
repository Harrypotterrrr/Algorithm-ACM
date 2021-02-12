/*
1306. Jump Game III
*/

class Solution {
public:
    
    vector<bool>flag;

    bool dfs(const vector<int>& arr, int id){
        if(arr[id] == 0)
            return true;
        
//         if(flag[id] == true)
//             return false;
        flag[id] = true;
        
        bool rtn;
        if(id + arr[id] < arr.size() && flag[id+arr[id]] == false)
            rtn = dfs(arr, id + arr[id]);
        if(rtn)
            return rtn;
        if(id - arr[id] >= 0 && flag[id-arr[id]] == false)
            rtn = dfs(arr, id - arr[id]);
        return rtn;
    }
    
    bool canReach(vector<int>& arr, int start) {
        for(int i=0;i<arr.size();i++)
            flag.push_back(false);
        return dfs(arr, start);        
    }
};

// bfs

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