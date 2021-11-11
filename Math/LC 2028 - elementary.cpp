/************************************************
Problem: 		2028. Find Missing Observations
Algorithm: 		Math
Difficulty: 	*
Importance:		***
Remark:			mean, remainder, qoetient
*************************************************/

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        // mean * (n + m) - sum(m) = left_sum
        // left_sum = n * x
        int summ = 0;
        for(auto &i: rolls) summ += i;
        int left_sum = mean * (n + rolls.size()) - summ;
        if(left_sum > 6 * n || left_sum < n) return {};
        int remainder = left_sum % n;
        vector<int>ans(n, left_sum / n);
        for(int i=0 ; i<remainder ; i++)
            ans[i] ++;
        return ans;
    }
};