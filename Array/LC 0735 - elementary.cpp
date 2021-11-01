/************************************************
Problem: 		735. Asteroid Collision
Algorithm: 		Array, Stack
Difficulty: 	*
Importance:		*
Remark:			
*************************************************/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>S;
        int n = asteroids.size();
        bool flag;
        for(int i=0 ; i<n ; i++){
            flag = true;
            auto &cur = asteroids[i];
            while(!S.empty() && S.top() > 0 && cur < 0){
                if(abs(cur) > S.top())
                    S.pop();
                else{
                    if(abs(cur) == S.top()) S.pop();
                    flag = false;
                    break;
                }
            }
            if(flag)
                S.push(asteroids[i]);
        }
        while(!S.empty()){
            ans.push_back(S.top());
            S.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};