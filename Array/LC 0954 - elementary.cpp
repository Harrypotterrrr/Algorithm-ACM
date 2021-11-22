/************************************************
Problem: 		954. Array of Doubled Pairs
Algorithm: 		Array, STL
Difficulty: 	*
Importance:		*
Remark:			
*************************************************/

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> uM;
        for(auto &i: arr) uM[i]++;
        vector<int>vec;
        for(auto &[i, ctr]: uM) vec.push_back(i);
        sort(vec.begin(), vec.end(), [](int &a, int &b){
            return abs(a) < abs(b) || (abs(a) == abs(b) && a < b);
        });
        for(auto &i: vec){
            if(uM[i] > uM[i*2]) return false;
            uM[i*2] -= uM[i];
        }
        return true;
    }
};


