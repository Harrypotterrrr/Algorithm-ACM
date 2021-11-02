/************************************************
Problem: 		266. Palindrome Permutation
Algorithm: 		String
Difficulty: 	*
Importance:		*
Remark:			
*************************************************/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        int n = s.size();
        vector<bool>vec(26);
        for(auto &i: s){
            if(vec[i-'a']) vec[i-'a'] = false;
            else vec[i-'a'] = true;
        }
        int ctr = 0;
        for(auto i: vec){
            if(i) ctr++;
            if(ctr > 1) return false;
        }
        return true;
    }
};