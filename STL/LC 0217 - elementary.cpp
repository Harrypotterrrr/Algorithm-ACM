/*
217. Contains Duplicate
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>uS;
        for(auto &i : nums){
            if(uS.find(i) != uS.end())
                return true;
            uS.insert(i);
        }
        return false;
    }
};