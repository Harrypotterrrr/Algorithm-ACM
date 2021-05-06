/*
136. Single Number
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> uS;
        for(auto &i : nums){
            if(uS.find(i) != uS.end())
                uS.erase(i);
            else
                uS.insert(i);
        }
        return *uS.begin();
    }
};

// Solution 2: unordered_map

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> uM;
        for(auto &i : nums){
            if(uM.find(i) ==  uM.end())
                uM[i] = 1;
            else
                uM[i]++;
        }
        for(auto &i : uM){
            if(i.second != 2)
                return i.first;
        }
        return 0;
    }
};

// Solution 3: sum

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> uS;
        long long set_sum = 0, num_sum = 0;
        for(auto &i : nums){
            if(!uS.count(i)){
                set_sum += i;
                uS.insert(i);
            }
            num_sum += i;
        }
        
        return int(set_sum * 2 - num_sum);
    }
};

// Solution 4: XOR operation

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto &i : nums){
            ans ^= i;
        }
        return ans;
    }
};