/*
241. Different Ways to Add Parentheses
*/

// Solution 1: divide and conquer

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>rtn1, rtn2, ans;
        for(int i=0 ; i<expression.size(); i++){
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
                rtn1 = diffWaysToCompute(expression.substr(0, i));
                rtn2 = diffWaysToCompute(expression.substr(i+1));
                for(auto &p : rtn1){
                    for(auto &q: rtn2){
                        if(expression[i] == '+')
                            ans.push_back(p+q);
                        else if(expression[i] == '-')
                            ans.push_back(p-q);
                        else
                            ans.push_back(p*q);
                    }
                }
            }
        }
        if(ans.size() == 0){
            return vector<int>({stoi(expression)});
        }
        return ans;
    }
};

// Solution 2: memorization optimization of solution 1



class Solution {
public:
    
    unordered_map<string, vector<int>>uM;
    vector<int> diffWaysToCompute(string expression) {
        if(uM.find(expression) != uM.end())
            return uM[expression];
        vector<int>rtn1, rtn2, ans;
        for(int i=0 ; i<expression.size(); i++){
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
                rtn1 = diffWaysToCompute(expression.substr(0, i));
                rtn2 = diffWaysToCompute(expression.substr(i+1));
                for(auto &p : rtn1){
                    for(auto &q: rtn2){
                        if(expression[i] == '+')
                            ans.push_back(p+q);
                        else if(expression[i] == '-')
                            ans.push_back(p-q);
                        else
                            ans.push_back(p*q);
                    }
                }
            }
        }
        if(ans.size() == 0){
            return uM[expression] = vector<int>({stoi(expression)});
        }
        return uM[expression] = ans;
    }
};