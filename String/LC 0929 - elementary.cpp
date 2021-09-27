/*
929. Unique Email Addresses
*/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>uS;
        for(auto &ss: emails){
            string tmp;
            int i=0;
            for(; i<ss.size() ; i++){
                if(ss[i] == '.') continue;
                if(ss[i] == '+' || ss[i] == '@') break;
                tmp += ss[i];
            }
            while(i < ss.size() && ss[i] != '@') i++;
            for(; i < ss.size() ; i++)
                tmp += ss[i];
            uS.insert(tmp);
        }
        return uS.size();
    }
};