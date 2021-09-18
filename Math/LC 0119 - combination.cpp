/*
119. Pascal's Triangle II
*/

// Solution 1: two-dimensional vector 2 * rowIndex
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>ans(2, vector<int>(rowIndex+1, 1));
        bool flag = false;
        for(int i=0 ; i<=rowIndex ; i++){
            for(int j=1 ; j<i ; j++){
                ans[flag][j] = ans[!flag][j-1] + ans[!flag][j];
            }
            flag = !flag;
        }
        return ans[!flag];
    }
};


// Solution 2: one-dimensional vector

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans(rowIndex+1, 1);
        for(int i=0 ; i<=rowIndex ; i++){
            for(int j=i-1 ; j>=1 ; j--){
                ans[j] = ans[j] + ans[j-1];
            }
        }
        return ans;
    }
};

// Solution 3: math combinations number

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans(rowIndex+1, 1);
        ans[0] = ans[rowIndex] = 1;
        int comb = 1;
        for(int i=1, a=rowIndex, b=1 ; i<=(rowIndex>>1) ; i++, a--, b++){
            long tmp = long(ans[i-1]) * a / b;
            ans[i] = ans[rowIndex-i] = tmp;
        }
        return ans;
    }
};