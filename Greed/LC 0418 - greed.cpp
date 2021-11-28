/************************************************
Problem: 		418. Sentence Screen Fitting
Algorithm: 		Greed, Dynamic Programming, Simulation
Difficulty: 	****
Importance:		***
Remark:			
*************************************************/

// Solution: TLE, simulation: O(NM), N is rows, M is cols

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        int ans = 0, ctr = 0, i = 0;
        int line_len = cols;
        for(auto &word: sentence) if(word.size() > cols) return 0;

        while(ctr < rows){ // this could fit
            auto &word = sentence[i];
            int cur_len = word.size();
            if(cur_len <= line_len){
                line_len -= cur_len + 1;
                i++;
            }
            else{
                ctr++;
                line_len = cols;
            }
            if(i == n){
                ans++;
                i = 0;
                if()
            }
        }
	    return ans;
    }
};

// Solution 2:

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        string s;
        for(auto &word: sentence){
            if(word.size() > cols) return 0;
            s += word + ' ';
        }
        int len = s.size();
        int total_len = 0;
        for(int i=0 ; i<rows ; i++){
            total_len += cols;
            if(s[total_len % len] == ' ') total_len ++;
            else{
                // while(s[total_len % len == 0 ? len - 1 : total_len % len - 1] != ' ')
                // the above is equal to the below:  M % N - 1 ===better way===> (M-1) % N !
                // because M % N - 1 could be negative number
                while(s[(total_len - 1) % len] != ' ')
                    total_len--;
            }
        }
	    return total_len / len;
    }
};


// Solution 3: TODO

