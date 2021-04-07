/*
168. Excel Sheet Column Title
*/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        int remainder;
        while(columnNumber){
            remainder = columnNumber % 26;
            if(remainder == 0){
                ans += 'Z';
                columnNumber -= 26;
            }
            else{
                ans += remainder - 1 + 'A';
            }
            columnNumber /= 26;

        }
        for(int i=0; i <ans.size()/2; i++)
            swap(ans[i], ans[ans.size() - i - 1]);
        return ans;
    }
};

// solution 2
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        int remainder;
        while(columnNumber){
            remainder = (--columnNumber) % 26;
            ans += 'A' + remainder;
            columnNumber /= 26;
        }
        return string(ans.rbegin(), ans.rend());
    }
};

// solution 3
class Solution {
public:
    string convertToTitle(int columnNumber) {
        return columnNumber == 0 ? "" : convertToTitle((columnNumber - 1) / 26) + char((columnNumber - 1) % 26 + 'A');
    }
};
