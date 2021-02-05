/*
67. Add Binary
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string ans(max(a.size(), b.size()) + 1, '0');
        
        int p_a = a.size()-1, p_b = b.size()-1, p_ans = ans.size()-1;
        int carry = 0;
        for(;p_a >=0 && p_b >=0;p_a--,p_b--){
            int cur_num = carry + (a[p_a] - '0') + (b[p_b] - '0');
            carry = cur_num / 2;
            ans[p_ans--] = cur_num % 2 + '0';
        }
        for(;p_a>=0;p_a--){
            int cur_num = carry + (a[p_a] - '0');
            carry = cur_num / 2;
            ans[p_ans--] = cur_num % 2 + '0';
        }
        for(;p_b>=0;p_b--){
            int cur_num = carry + (b[p_b] - '0');
            carry = cur_num / 2;
            ans[p_ans--] = cur_num % 2 + '0';
        }
        if(carry == 1)
            ans[p_ans--] = '1';

//         for(int i=0;i<ans.size();i++)
//             if(ans[i] !='0')
//                 return ans.substr(i);
//         return "0";
        auto id = ans.find_first_not_of('0');
        if(id == string::npos)
            return "0";
        return ans.substr(id);
    }
};