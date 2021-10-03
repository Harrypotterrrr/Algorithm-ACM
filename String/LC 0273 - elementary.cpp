/*
273. Integer to English Words
*/

class Solution {
public:
    
    vector<string> dict1 = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    
    vector<string> dict2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    vector<string> dict3 = {
        "Billion", "Million", "Thousand", "Hundred", ""
    };
    
    vector<int> nums1 = {
        1000000000, 1000000, 1000, 100, 10, 1
    };
        
    string numberToWords(int num) {
        if(!num) return "Zero";
        string ans;
        for(int i=0 ; num && i<3 ; i++){
            int qoe = num / nums1[i];
            if(!qoe) continue;
            ans += hundred2str(qoe);
            ans += " "+ dict3[i];
            num = num % nums1[i];
        }
        ans += hundred2str(num);
        return ans.erase(0, 1);
    }
    string hundred2str(int num) {
        string rtn;
        for(int i=3 ; num && i<nums1.size() ; i++){
            int t = num / nums1[i];
            if(!t) continue;
            if(i == 3)
                rtn += " " + dict1[t] + " " + dict3[i];
            else if(i == 4 && t >= 2)
                rtn += " " + dict2[t];
            else{
                rtn += " " + dict1[num];
                break;
            }
            num = num % nums1[i];
        }
        return rtn;
    }
};