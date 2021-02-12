/*
1345. Jump Game IV
*/

class Solution {
public:

    int minJumps(vector<int>& arr) {
        
        if(arr.size() == 1)
            return 0;
        
        unordered_map<int, vector<int>> um;
        for(int i=0 ; i<arr.size();i++){
            um[arr[i]].push_back(i);
        }
        
        vector<bool> flag(arr.size(), false);
        flag[0] = true;
        queue<int>Q;
        Q.push(0);
        
        int ctr = 0;
        
        
        while(!Q.empty()){
            int size = Q.size();
            while(size--){
                int cur = Q.front();
                Q.pop();

                int next = cur + 1;
                if(next == arr.size() - 1){
                    return ctr + 1;
                }
                if(next < arr.size() && !flag[next]){
                    flag[next] = true;
                    Q.push(next);
                }
                next = cur - 1;
                if(next == arr.size() - 1){
                    return ctr + 1;
                }
                if(next >= 0 && !flag[next]){
                    flag[next] = true;
                    Q.push(next);
                }
                
                if(um.find(arr[cur]) == um.end())
                    continue;
                vector<int>&tmp_vec = um[arr[cur]];
                for(auto i=0 ; i<tmp_vec.size(); i++){
                    if(tmp_vec[i] == arr.size() - 1){
                        return ctr + 1;
                    }
                    if(!flag[tmp_vec[i]]){
                        flag[tmp_vec[i]] = true;
                        Q.push(tmp_vec[i]);
                    }
                }
                um.erase(arr[cur]);
            }
           
            ctr++;
        }
        return ctr;
    }
};
