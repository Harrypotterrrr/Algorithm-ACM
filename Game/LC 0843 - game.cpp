/************************************************
Problem: 		843. Guess the Word
Algorithm: 		String, Random, Game Theory
Difficulty: 	****
Importance:		***
Remark:			minmax algorithm (not in AI)
*************************************************/

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

// Solution 1: Game + Random

class Solution {
public:
    
    int match_num(string &s1, string &s2){
        int ctr = 0;
        for(int i=0 ; i<s1.size() ; i++)
            if(s1[i] == s2[i])
                ctr++;
        return ctr;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        srand(time(NULL));
        for(int i=0 ; i<10 ; i++){
            int n = wordlist.size();
            int id = rand() % n;
            int correct_num = master.guess(wordlist[id]);
            if(correct_num == 6) break;
            vector<string>tmp;
            for(int j=0 ; j<n ; j++)
            if(match_num(wordlist[j], wordlist[id]) == correct_num && j != id)
                tmp.push_back(wordlist[j]);
            wordlist = tmp;
        }
    }
};

// Solution 2:

// The probability of two words with 0 match is (25/26)^6 = 80%. That is to say, for a candidate word, we have 80% chance to see 0 match with the secret word. In this case, we had 80% chance to eliminate the candidate word and its "family" words which have at least 1 match. Additionally, in order to delete a max part of words, we select a candidate who has a big "family" (fewest 0 match with other words).

class Solution {
public:
    
    int match_num(string &s1, string &s2){
        int ctr = 0;
        for(int i=0 ; i<s1.size() ; i++)
            if(s1[i] == s2[i])
                ctr++;
        return ctr;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        
        while(true){
            
            // pick the best candidate number from the wordlist to eliminate the most number of word
            
            int n = wordlist.size();
            unordered_map<string, int> uM; 
            for(auto &i: wordlist){
                for(auto &j: wordlist){
                    if(match_num(i, j) == 0)
                        uM[i]++;
                }
            }
            pair<string, int> candidate = {"", INT_MAX};
            for(auto &word: wordlist)
                if(uM[word] <= candidate.second)
                    candidate = {word, uM[word]};
            
            // guess and filter
            int correct_num = master.guess(candidate.first);
            if(correct_num == 6) break;
            vector<string> tmp;
            for(int i=0 ; i<n ; i++)
                if(match_num(candidate.first, wordlist[i]) == correct_num && wordlist[i] != candidate.first)
                    tmp.push_back(wordlist[i]);
            wordlist = tmp;
        }
    }
};
