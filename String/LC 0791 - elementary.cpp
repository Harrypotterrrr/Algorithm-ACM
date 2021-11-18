/************************************************
Problem: 		791. Custom Sort String
Algorithm: 		String, STL
Difficulty: 	*
Importance:		*
Remark:			
*************************************************/

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int>uM;
        for(auto &c: s) uM[c]++;
        string ans;
        for(auto &c: order){
            for(int i=uM[c] ; i>0 ; i--) ans += c;
            uM.erase(c);
        }
        for(auto &[c, num]: uM)
            for(int i=num ; i>0 ; i--) ans += c;
        return ans;
    }
};