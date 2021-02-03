/*
43. Multiply Strings
*/
class Solution {
public:
    
    string reverse(string sstr){
        string ans = "";
        for(int i=sstr.size()-1;i>=0;i--){
            ans += sstr[i];
        }
        return ans;
    }
    
    string addBig(string base, string adder, int offset){
        int carry = 0;
        int i=offset;
        for(;i < adder.size() + offset;i++){
            int cur_num;
            if(i < base.size())
                cur_num = (base[i] - '0') + (adder[i-offset] - '0') + carry;
            else
                cur_num = (adder[i-offset] - '0') + carry;
            carry = cur_num/10;
            cur_num = cur_num%10;
            
            if(i < base.size())
                base[i] = cur_num + '0';
            else
                base += cur_num + '0';
        }
        if(carry == 1)
            base += '1';
        return base;
    }
    
    string multiplySingle(string base, char single){
        string ans = "";
        int carry = 0;
        for(auto i=0;i<base.size();i++){
            int cur_num = (base[i] - '0') * (single - '0') + carry;
            carry = cur_num/10;
            cur_num = cur_num%10;
            ans += cur_num + '0';
        }
        if(carry >= 1)
            ans += (carry + '0');
        return ans;
    }
    
    string multiply(string num1, string num2) {
        
        if(num1 == "0" || num2 == "0")
            return "0";
        
        string num1_r = reverse(num1);
        string num2_r = reverse(num2);
        string rtn = "0";
        
        for(auto i=0;i<num2_r.size();i++){
            string mul_sing = multiplySingle(num1_r, num2_r[i]);
            rtn = addBig(rtn, mul_sing, i);
        }
        return reverse(rtn);
    }
};

// Solution 2
class Solution {
public:
    string multiply(string num1, string num2) {

        string res(num1.size() + num2.size(), '0');

        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                int prod =  (num1[i] - '0') * (num2[j] - '0') +  (res[i + j + 1] - '0');
                res[i+j+1] = (prod % 10) + '0';
                res[i+j] = ((prod /10) + (res[i + j] - '0')) + '0';

            }
        }
        int i=0;
        for(;i<res.size();i++)
            if(res[i]!= '0')
                break;
        if(i>=res.size())
            return "0";
        return res.substr(i);
    }
};