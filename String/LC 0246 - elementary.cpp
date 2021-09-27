/*
246. Strobogrammatic Number
*/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int left = 0, right = num.size()-1;
        while(left <= right){
            if(num[left] == '6' && num[right] == '9' ||
              num[left] == '9' && num[right] == '6' ||
              num[left] == '8' && num[right] == '8' || 
              num[left] == '0' && num[right] == '0' ||
              num[left] == '1' && num[right] == '1'){
                left ++;
                right --;
                continue;
            }
            return false;
        }
        return true;
    }
};