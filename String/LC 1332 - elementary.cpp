/************************************************
Problem: 		1332. Remove Palindromic Subsequences
Algorithm: 		String
Difficulty: 	*
Importance:		*
Remark:			
*************************************************/

class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.size();
        for(int i=0 ; i<n ; i++){
            if(s[i] != s[n-i-1])
                return 2;
        }
        return 1;
    }
};