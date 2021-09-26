/*
56. Merge Intervals
*/

class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> first;
        vector<int> second;
        for(auto &i: intervals){
            first.push_back(i[0]);
            second.push_back(i[1]);
        }
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());
        vector<vector<int>> ans;
        int start = first[0], p = 1;
        while(p < first.size()){
            if(first[p] > second[p-1]){
                vector<int>tmp({start, second[p-1]});
                ans.push_back(tmp);
                start = first[p];
            }
            p ++;
        }
        ans.push_back({start, second[p-1]});
        return ans;
    }
};