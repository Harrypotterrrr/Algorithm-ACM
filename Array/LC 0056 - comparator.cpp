/*
56. Merge Intervals
*/

class Solution {
public:
    
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        
        vector<vector<int>> ans({intervals[0]});
        for(int i=1;i<intervals.size();i++){
            if(ans.back()[1] >= intervals[i][0])
                ans.back()[1] = ans.back()[1] > intervals[i][1] ? ans.back()[1] : intervals[i][1];
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};