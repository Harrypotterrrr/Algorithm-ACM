/************************************************
Problem: 		680. Valid Palindrome II
Algorithm: 		String
Difficulty: 	*
Importance:		*
Remark:			
*************************************************/

class Solution {
public:
    bool validPalindrome(string s) {
        return solve(s, 0, s.size()-1, 1);
    }
    
    bool solve(string &s, int left, int right, int k){
        if(left >= right) return true;
        if(s[left] == s[right]) return solve(s, left + 1, right - 1, k);
        if(k == 0) return false;
        return solve(s, left + 1, right, k-1) || solve(s, left, right-1, k-1);
    }
};