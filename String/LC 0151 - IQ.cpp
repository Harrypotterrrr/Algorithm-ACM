/*
151. Reverse Words in a String
*/

class Solution {
public:
    string reverseWords(string s) {
        // reverse(s.begin(), s.end());
        for(int i=0 ; i<s.size()>>1 ; i++)
            swap(s[i], s[s.size() - i - 1]);
        
        int p = 0, start;
        for(int i=0 ; i<s.size() ;i++){
            if(p != 0){
                s[p] = ' ';
                p++;
            }
            while(i < s.size() && s[i] == ' ')
                i++;
            if(i >= s.size()){
                p -= 1;
                break;
            }
            start = i;
            while(i < s.size() && s[i] != ' '){
                s[p+i-start] = s[i];
                i++;
            }
            reverse(s.begin() + p, s.begin() + p + i-start);
            p += i-start;
        }
        s.resize(p);

        
        return s;
    }
};

// Solution 2: optimization
class Solution {
public:
    string reverseWords(string s) {
        int p = 0, n = s.size(), start;
        for(int i=0 ; i<s.size() >> 1 ; i++)
            swap(s[i], s[s.size() - 1 -i]);
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] != ' '){
                if(p != 0){
                    s[p] = ' ';
                    p ++;
                }
                start = i;
                while(i < s.size() && s[i] != ' '){
                    s[p + i - start] = s[i];
                    i++;
                }
                reverse(s.begin() + p, s.begin() + p + i - start);
                p += i - start;
            }
        }
        s.resize(p);
        return s;
    }
};