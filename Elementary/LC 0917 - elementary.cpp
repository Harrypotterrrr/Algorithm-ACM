/*
917. Reverse Only Letters
*/

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int p = 0, q = s.size() - 1;
        while(q > p){
            while(!isAlphabet(s[p]) && q > p) p++;
            while(!isAlphabet(s[q]) && q > p) q--;
            swap(s[p], s[q]);
            p++; q--;
        }
        return s;
    }
    
    bool isAlphabet(char &c){
        if((c>='a' && c<='z') || (c>='A' && c<='Z'))
            return true;
        return false;
    }
};