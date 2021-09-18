/*
282. Expression Add Operators
*/

class Solution {
public:
    
    vector<string> ans;
    vector<string> addOperators(string num, int target) {
        solve(num, "", 0, target, 0, 0);
        return ans;
    }
    
    void solve(string& num, string cur, int start, int target, long sum, int diff){
        if(start >= num.size()){
            if(target == sum)
                ans.push_back(cur);
            return;
        }
        string tmp; 
        long cur_num;
        for(int i=start ; i<num.size() ; i++){
            tmp = num.substr(start, i-start+1);
            if(tmp.size() > 1 && tmp[0] == '0')
                break;
            cur_num = stol(tmp);
            if(!cur.size()){
                solve(num, tmp, i+1, target, cur_num, cur_num);
            }
            else{
                solve(num, cur + '+' + tmp, i+1, target, sum+cur_num, cur_num);
                solve(num, cur + '-' + tmp, i+1, target, sum-cur_num, -cur_num);
                solve(num, cur + '*' + tmp, i+1, target, sum+diff*(cur_num-1), diff*cur_num);
            }
        }
    }
    
};


