/*
1678. Goal Parser Interpretation
*/

class Solution {
public:
    string interpret(string command) {
        string rtn;
        for(auto i=0;i<command.size();i++){
            if(command[i] == 'G')
                rtn+= command[i];
            else if(command[i] == '('){
                if(command[i+1] == ')' ){
                    rtn += 'o';
                    i += 1;
                }
                else if(command[i+1] == 'a'){
                    rtn += "al";
                    i += 2;
                }
            }
        }
        return rtn;
    }
};