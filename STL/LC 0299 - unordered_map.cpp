/************************************************
Problem: 		299. Bulls and Cows
Algorithm: 		STL
Difficulty: 	*
Importance:		*
Remark:			unordered_map
*************************************************/


// Solution 1: 

class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        int n = secret.size();
        unordered_map<int, int> uM_secret, uM_guess;
        
        for(int i=0 ; i<n ; i++){
            if(secret[i] == guess[i]) bull++;
            else{
                uM_secret[secret[i]] ++;
                uM_guess[guess[i]] ++;
            }
        }
        for(auto &[num, k]: uM_guess)
            cow += min(k, uM_secret[num]);
        return to_string(bull) + 'A' + to_string(cow) + 'B';
    }
};

// Solution 2: save space

class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        int n = secret.size();
        unordered_map<int, int> uM;
        
        for(int i=0 ; i<n ; i++){
            if(secret[i] == guess[i]) bull++;
            else{
                if(uM[secret[i]] < 0) cow++;
                uM[secret[i]]++;
                if(uM[guess[i]] > 0) cow++;
                uM[guess[i]] --;
            }
        }
        return to_string(bull) + 'A' + to_string(cow) + 'B';
    }
};