/*
38. Count and Say
*/

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string ss = countAndSay(n-1);
        string rtn;
        char c = ss[0];
        int ctr = 1;
        for(auto i=1 ; i<ss.size() ; i++){
            if(ss[i] != c){
                rtn += '0' + ctr;
                rtn += c;
                c  = ss[i];
                ctr = 1;
            }
            else
                ctr += 1;
        }
        rtn += '0' + ctr;
        rtn += c;
        return rtn;
    }
};