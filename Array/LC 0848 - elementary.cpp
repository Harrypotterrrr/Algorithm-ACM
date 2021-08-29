/*
848. Shifting Letters
*/


class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        
        shifts[shifts.size()-1] %= 26;
        for(int i=shifts.size()-2 ; i>=0 ; i--){
            shifts[i] = (shifts[i] % 26 + shifts[i+1]) % 26;
        }
        
        for(int i=0 ; i<s.size() ; i++){
            s[i] = shift(s[i], shifts[i]);
        }
        return s;
    }
    char shift(char c, int k){
        c = (c - 'a' + k) % 26 + 'a';
        return c;
    }
};