/*
1189. Maximum Number of Balloons
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int>M;
        string s = "balon";
        int ans = INT_MAX;
        for(auto &i: text) M[i] ++;
        for(auto &i: s){
            if(i == 'l' || i == 'o')
                ans = min(ans, M[i] >> 1);
            else
                ans = min(ans, M[i]);
        }
        return ans;
    }
};