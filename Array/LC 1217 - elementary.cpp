/************************************************
Problem: 		1217. Minimum Cost to Move Chips to The Same Position
Algorithm: 		Array
Difficulty: 	*
Importance:		*
Remark:			
*************************************************/

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size();
        int odd_ctr = 0, even_ctr = 0;
        for(int i=0 ; i<n ; i++){
            if(position[i] % 2) even_ctr++;
            else odd_ctr ++;
        }
        return odd_ctr < even_ctr ? odd_ctr : even_ctr;
    }
};