/*
151. Reverse Words in a String
*/

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        s.clear();
        string tmp;
        ss >> s;
        while(ss >> tmp){
            s = tmp + ' ' + s;
        }
        return s;
    }
};

// Solution2 : getline

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        s.clear();
        string tmp;
        while(getline(ss, tmp, ' ')){
            if(tmp.empty())
                continue;
            s = s.empty() ? tmp : tmp + ' ' + s;
        }
        return s;
    }
};